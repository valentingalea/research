
int test()
{
	struct Base {
		Base() {
			printf("Base\n");
		}
		~Base() {
			printf("~Base\n");
		}
	};

	struct MemberA {
		MemberA() {
			printf("Member A\n");
		}
		~MemberA() {
			printf("~Member A\n");
		}
	};

	struct MemberB {
		MemberB() {
			printf("Member B\n");
		}
		~MemberB() {
			printf("~Member B\n");
		}
	};

	struct Derived : public Base {
		Derived() {
			printf("Derived\n");
		}
		~Derived() {
			printf("~Derived\n");
		}
		MemberA mA;
		MemberB mB;
	};

	{ Derived d; }

	// order is
	// construction:
	// Base
	// Member A
	// Member B
	// Derived
	// destruction:
	// ~Derived
	// ~Member B
	// ~Member A
	// ~Base

	return 0;
}