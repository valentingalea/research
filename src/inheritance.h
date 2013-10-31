int encode(char a, char b, char c, char d)
{
	return a | b << 8 | c << 16 | d << 24;
}

int test()
{
	struct base {
		int b;
	};

	struct derived_a : public /*virtual*/ base {
		int d_a;
	};

	struct derived_b : public /*virtual*/ base {
		int d_b;
	};

	struct multiple : public derived_a, public derived_b {
		int d_m;
	};

	multiple m;
	((derived_a&)m).b = encode('B', 'A', 'S', 'E');
	((derived_b&)m).b = encode('B', 'A', 'S', 'E');
	m.d_a = encode('1', '1', '1', '1');
	m.d_b = encode('2', '2', '2', '2');
	m.d_m = encode('M', 'E', 'M', 'B');

	// mem layout for the non virtual inheritance:
	// BASE 1111 BASE 2222 MEMB

	// mem layout for the virtual inheritence: (<ptr> is pointer/offset to BASE)
	// <ptr> 1111 <ptr> 2222 MEMB BASE
	
	return 0;
}
