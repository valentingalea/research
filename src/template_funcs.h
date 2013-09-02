//
// there is no real diff between 'class' and 'typename'
// when declaring templates args although there are some gotchas
// see http://stackoverflow.com/questions/2023977/c-difference-of-keywords-typename-and-class-in-templates
//

//
// function template
// can be called with either:
//	max<type>(...) or
//	max(...) - the compiler can deduce the type
//
template<typename T> T max(T a, T b)
{
	return a >= b ? a : b;
}

//
// full specialization for the above template function
//
template<> int max(int a, int b)
{
	return 0;
}

//
// templated class
// is used with:
//	example<type> var = ...;
//
template<typename T> class example
{
	T member;
};

//
// template class FULL specialization
// a whole different interface
//
template<> class example<char>
{
	char a_different_member;
};

//
// template class PARTIAL specialization
// just define behaviour for"
// pointer, reference, pointer to member, or function pointer types
//
template<typename T> class example<T *>
{
	T *pointer;
};

//
// more info
// http://msdn.microsoft.com/en-us/library/3967w96f%28v=vs.80%29.aspx
// http://www.cprogramming.com/tutorial/template_specialization.html
//
int test()
{
	example<int> e1;
	example<char> e2;
	example<float *> e3;

	return 0;
}