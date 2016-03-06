#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <deque>
#include <random>
#include <functional>
#include <cassert>
#include <cstdio>
#include <cstdlib>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////

template<typename T>
struct non_copy
{
	non_copy() = default;
	non_copy(const non_copy &) = delete;
	non_copy& operator=(const non_copy &) = delete;
};

template<typename T>
struct non_move
{
	non_move() = default;
	non_move(non_move &&) = delete;
	non_move& operator=(non_move &&) = delete;
};

using job_t = std::function<void()>;
using lock_t = std::unique_lock<std::mutex>;
using critical_section_t = std::lock_guard<std::mutex>;

struct notification_queue
{
	std::deque<job_t>		items;
	bool					done = false;
	std::mutex				mutex;
	std::condition_variable	ready_cv;
	// these 2 vars are NOT CopyConstructible nor MoveConstructible
	// making the whole class the same, thus deleting the constructors and operators
	// more info: http://stackoverflow.com/questions/29986208/how-should-i-deal-with-mutexes-in-movable-types-in-c

	bool pop(job_t &out_job)
	{
		lock_t lock(mutex); // also aquires the lock
		
		// this form avoids spurious wakeup
		// also it will release the lock before going into wait
		ready_cv.wait(lock, [&] { return !items.empty() || done; });
		// when wait exits, lock is reaquired

		if (items.empty()) {
			return false;
		}

		out_job = std::move(items.front());
		items.pop_front();

		return true;
	}   // release lock on destruction

	template<typename T>
	void push(T&& job)
	{
		{
			critical_section_t cs(mutex);
			items.emplace_back(std::forward<T>(job));			
		}
		ready_cv.notify_one();	
	}

	void finish()
	{
		{
			critical_section_t cs(mutex);
			done = true;
		}
		ready_cv.notify_all();
	}
};

struct job_system : non_copy<job_system>, non_move<job_system>
{
	unsigned int					th_count{ std::thread::hardware_concurrency() };
	std::vector<std::thread>		threads;
	std::atomic_uint				q_index = 0; // tracker to help pidgeonholing jobs to queues
	const unsigned int				q_max = th_count; // either 1 to force a global queue or th_count to dedicate a queue per thread
	std::vector<notification_queue>	queues{ th_count }; // has to init here (calls .reserve()) due to NotCopy, NotMove nature of the queue class

	job_system()
	{
		// create and start the threads
		for (auto i = 0u; i < th_count; ++i) {
			threads.emplace_back([this, i](void){
				run(i);
			});
		}
	}
	~job_system()
	{
		// send done signal (can process last pending job)
		for (auto &q : queues) {
			q.finish();
		}

		// blocks until all threads finish
		for (auto &i : threads) {
			i.join();
		}
	}

	void run(int thread_id)
	{
		while (true) {
			// grab new job - blocking
			job_t job;
			if (!queues[thread_id % q_max].pop(job)) {
				return;
			}

			// execute it
			job();
		}
	}

	template<typename F>
	void async(F&& new_job)
	{
		auto i = q_index++;
		queues[i % q_max].push(std::forward<F>(new_job));
	}
};

#define RMT_ENABLED 0
#include "../lib/Remotery/lib/Remotery.h"

struct telemetry
{
	Remotery* rmt;

	telemetry()
	{
		rmt = nullptr;
		assert(RMT_ERROR_NONE == rmt_CreateGlobalInstance(&rmt));
	}
	~telemetry()
	{
		if (rmt) {
			rmt_DestroyGlobalInstance(rmt);
		}
	}
};

thread_local std::random_device rd;
thread_local std::mt19937 gen(1779);

int main()
{
	telemetry t; // only on main thread

	using tclock_t = std::chrono::steady_clock;
	using tpoint_t = tclock_t::time_point;
	tpoint_t t_start, t_end;

	{
		job_system jobs;

		auto count = std::uniform_int_distribution<int>(1, 50)(gen);
		printf("will process %i jobs...\n", count);

		t_start = t_end = tclock_t::now();
		std::mutex tmutex;

		for (auto i = 0; i < count; ++i) {
			jobs.async([i, &t_end, &tmutex](void) {
				constexpr int descript_len = 32;
				char descript[descript_len];
				snprintf(descript, descript_len, "job %i\0", i);
				rmt_BeginCPUSampleDynamic(descript);

				auto time = std::uniform_int_distribution<int>(100, 500)(gen);
				std::this_thread::sleep_for(std::chrono::milliseconds(time));

				tpoint_t t = tclock_t::now(); {
					critical_section_t cs(tmutex);
					if (t > t_end) {
						t_end = t;
					}
				}

				rmt_EndCPUSample();
				printf("done %s\n", descript);
			});

			auto time = std::uniform_int_distribution<int>(20, 200)(gen);
			std::this_thread::sleep_for(std::chrono::milliseconds(time));
			printf("new job %i\n", i);
		}

		// destructor waits on jobs
	}

	using tdiff_t = std::chrono::duration<float, std::chrono::seconds::period>;
	auto elapsted = tdiff_t(t_end - t_start).count();
	printf("Running time: %f\n", elapsted);

	std::system("pause");

	return 0;
}