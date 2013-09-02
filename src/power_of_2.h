#include <cmath>

bool is_power_of_2(int n)
{
	return n > 0 && (n & (n - 1)) == 0;
}

double next_power_of_2_slow(int n)
{
	// first we compute the base 2 logaritm of n
	// that is the number we have to raise 2 in order to get n
	// usually C/C++ lacks that function so we use the trick
	// log base b of x = log base <any> of x / log base <any> of 2
	// here <any> being 10 (the standard log function from math.h
	//
	// then we just raise x to that number, making sure
	// we first round it to the nearest integer
	return pow(2, ceil(log(n)/log(2)));
}

int next_power_of_2_fast(int n)
{
	// more info here:
	// http://acius2.blogspot.co.uk/2007/11/calculating-next-power-of-2.html
	//
	n--; // substract one in order for actual powers of 2 to also work
	n = (n >> 1) | n;
	n = (n >> 2) | n;
	n = (n >> 4) | n;
	n = (n >> 8) | n;
	n = (n >> 16) | n;
	n++;

	return n;
}

// x86 VC only
//int __declspec( naked ) next_power_of_2_asm(int n) 
//{ 
//	__asm
//	{								
//		dec ecx
//		bsr ecx, ecx // get the number of the first bit that is set to 1, scanning from MSB to LSB 
//		mov eax, 2
//		rol eax, cl
//		ret
//	}
//}

// GCC inline assembly AT&T syntax
//int next_power_of_2_asm(int n) 
//{
//	int out;
//
//	asm(								
//		"decl %%ecx;"
//		"bsr %%ecx, %%ecx;" // get the number of the first bit that is set to 1, scanning from MSB to LSB 
//		"movl $2, %%eax;"
//		"roll %%cl, %%eax;"
//		: "=a" (out) // output result goes in EAX
//		: "c" (n) // input captured variable goes into ECX
//	);
//
//	return out;
//}

int test()
{
	bool b1 = is_power_of_2(8);
	bool b2 = is_power_of_2(13);

	int should_be_8 = next_power_of_2_fast(7);
	int should_be_32 = next_power_of_2_fast(17);

	return 0;
}