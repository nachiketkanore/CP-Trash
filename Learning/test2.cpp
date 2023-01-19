#include <iostream>
using namespace std;

class A {
	private:
	int side;

	public:
	A(int side) : side(side) {
	}
	friend void area(A a);
};

// friend function is not member function of any class
// it is simply globally declared function
void area(A a) {
	cout << a.side * a.side << endl;
}

// exception handling using try, catch and throw in c++
void test(int a, int b) {
	cout << "Input: a = " << a << ", b = " << b << endl;
	try {
		if (b == 0)
			throw "Divide by zero error\n";
		cout << a / b << endl;
	} catch (const char* error) {
		cout << error << endl;
	}
}

int main() {
	// A a(20);
	// area(a);
	int a, b;
	while (cin >> a >> b) {
		test(a, b);
	}
}
