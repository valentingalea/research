template<typename T> struct Base
{
	void method()
	{
		static_cast<T *>(this)->method();
	}
};

struct Derived : public Base<Derived>
{
	void method()
	{
		printf("Derived::method");
	}
};

int test()
{
	Derived d;
	Base<decltype(d)> *b = &d;
	
	b->method();

	return 0;
}