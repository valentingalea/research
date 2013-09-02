#include <functional>

int test()
{
	// type-of-lambda: just a function pointer
	// because the lambda doesn't capture anything
	typedef int (*funcptr)(int arg);
	funcptr func = [](int arg) { return 0; };

	// type-of-lambda: a special compiler created anonymous class
	auto func2 = [](int arg) { return arg; };

	// type-of-lambda: the templated std::function instantiated
	// with the signature of the lambda
	std::function<void (int arg)> func3 = [] (int arg) { return; };

	return 0;
}