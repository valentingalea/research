#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

template<typename T> struct node
{
	T data;
	node *next;

	node(const T &value) : data(value), next(nullptr) {}
private:
	node(const node &);
	node(const node &&);
};

template<typename T> struct list
{
	typedef node<T> elem;
	elem * first;
	elem * last;

	list() :
		first(nullptr), last(first)
	{
	}

	void push_back(const T& item)
	{
		elem *n = new elem(item);

		if( last != nullptr )
			last->next = n;

		last = n;

		if( first == nullptr ) {
			first = last;
		}
	}

	void push_front(const T& item)
	{
		elem *n = new elem(item);
		n->next = first;

		first = n;

		if( last == nullptr ) {
			last = first;
		}
	}

	//
	// example of an thread-safe push_front
	// by employing atomic variables
	//
	// we only care for atomicity and not sync or ordering
	// so we use std::memory_order_relaxed
	// the default is std::memory_order_seq_cst which is
	// the most consuming but guarantees everything that happened-before
	// a store in one thread becomes a visible side effect in the tread that did a load, 
	// and also establishes a single total modification order
	// of all atomic operations that are so tagged
	//
	// more at http://en.cppreference.com/w/cpp/atomic/memory_order
	//
	//std::atomic<elem *> first;
	//void atomic_push_front(const T& item)
	//{
	//	elem *n = new elem(item);
	//	n->next = first.load(std::memory_order_relaxed);

	//	// using the _strong version here that doesn't allow spurious wakeup
	//	std::atomic_compare_exchange_strong_explicit(
	//		&first, // value to change
	//		&n->next, // expected value to find at address
	//		n, // new value to write if old value still present
	//		std::memory_order_release, // mem sync order technique on success
	//		std::memory_order_relaxed, // mem sync order technique on failure
	//	);
	//}

	void traverse(void (*func)(T &))
	{
		for( elem *i = first; i; i = i->next )
			func(i->data);
	}
};

int test()
{
	list<int> l;

	std::mutex m;
	std::condition_variable cv;
	std::unique_lock<std::mutex> lock(m);
	std::atomic_bool done1;
	std::atomic_bool done2;
	done1.store(false);
	done2.store(false);

	std::thread t1([&](){
		for( int i = 0; i < 10; i++ ) {
			//printf("X");
			//std::this_thread::sleep_for(std::chrono::microseconds(100));
			l.push_back(i);
		}

		done1.store(true);
		cv.notify_one();
	});
	std::thread t2([&](){
		for( int i = 0; i < 10; i++ ) {
			//printf("O");
			//std::this_thread::sleep_for(std::chrono::microseconds(200));
			l.push_back(1);
		}

		done2.store(true);
		cv.notify_one();
	});

	t1.detach();
	t2.detach();
	cv.wait(lock, [&]{ return done1 && done2; });

	l.traverse( [](int& n){ printf("%i", n); } );

	return 0;
}