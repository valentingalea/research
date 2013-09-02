bool is_prime(int n)
{
	int limit =
		n / 2 // all divisors are less than or equal to n/2
//		sqrt(n); // further optimization
//		6k +- 1 < sqrt(n) // see http://en.wikipedia.org/wiki/Primality_test
	;

	for(int i = 2; i < limit; i++ )
		if( n % i == 0 )
			return false;

	return true;
}

int test()
{
	bool b1 = is_prime(7);
	bool b2 = is_prime(22);
	bool b3 = is_prime(37);

	return 0;
}