template<typename T> void xorSwap(T &x, T &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}

template<typename T> void plusSwap(T &x, T &y)
{
	x += y;
	y = x - y;
	x -= y;
}

void reverse_string(char *str, int length)
{
	for(int l = 0, r = length - 1; l < r; l++, r-- )
		xorSwap(str[l], str[r]);
}

int test()
{
	char str[] = "hello world";
	reverse_string(str, 11);

	return 0;
}