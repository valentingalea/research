#include <cstdint>

struct A
{
	int data;
	void non_virtual_method() { printf("non virtual\n"); }
	virtual void virtual_method_1() { printf("virtual 1\n"); }
	virtual void virtual_method_2() { printf("virtual %d\n", data); }
};

int test()
{
	A *a = new A;

	a->data = 123;
	
//	mov         ecx,dword ptr [a]		// this pointer is passed in ECX
//	call        A::non_virtual_method
	a->non_virtual_method();

//	mov         eax,dword ptr [a]		// get address of start of a, that is the vtable
//	mov         edx,dword ptr [eax]		// load the vtable address in EDX
//	mov         eax,dword ptr [edx+4]	// load the address of the desired function in EAX, with the correct offset from the vtable
//	mov         ecx,dword ptr [a]		// this pointer is passed in ECX
//	call        eax						// call the function now that we resolved the address
	a->virtual_method_2();

//
// manually call the virtual function from the vtable
//
	typedef void (*signature)();
	signature method;

	std::intptr_t *vtable = *reinterpret_cast<std::intptr_t **>(a);
	method = reinterpret_cast<signature>(vtable[1]);

	__asm mov ecx, dword ptr [a] // prepare this pointer for the class method
	method();

	return 0;

}