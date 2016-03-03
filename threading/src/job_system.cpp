#include <cassert>
#include <thread>
#include <mutex>
#include <vector>
#include <deque>
#include <cstdio>

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

using job_t = void(*)(void);
using lock_t = std::unique_lock<std::mutex>;
using critical_section_t = std::lock_guard<std::mutex>;

struct notification_queue
{
	std::deque<job_t>		items;
	std::mutex				mutex;
	std::condition_variable	ready_cv;

	void pop(job_t &out_job)
	{
		lock_t lock(mutex); // also aquires the lock
		
		// this form avoids spurious wakeup
		// also it will release the lock before going into wait
		ready_cv.wait(lock, [&] { return !items.empty(); }); 
		// when wait exits, lock is reaquired

		out_job = std::move(items.front());
		items.pop_front();
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
};

struct job_system : non_copy<job_system>, non_move<job_system>
{
	int							count;
	std::vector<std::thread>	threads;
	notification_queue			queue;

	job_system()
	{
		count = std::thread::hardware_concurrency();
		assert(count);

		// create & start the threads
		for (auto i = 0; i < count; ++i) {
			threads.emplace_back([&, i](void){
				run(i);
			});
		}
	}
	~job_system()
	{
		// blocks until all threads finish
		for (auto &i : threads) {
			i.join();
		}
	}
	
	void run(int thread_id)
	{
		while (true) {
			// grab new job - blocking
			job_t job{};
			queue.pop(job);

			// execute it
			job();
		}
	}

	template<typename F>
	void async(F&& new_job)
	{
		queue.push(std::forward<F>(new_job));
	}
};

int main()
{
	job_system jobs;

	jobs.async([](void){
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		printf("job A\n");
	});

	// run the jobs system and return
	return 0;
}