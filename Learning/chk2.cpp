#include <iostream>
using namespace std;

class nachiket {
	public:
	int x;
	nachiket() {
		x = 21;
	}
	nachiket(nachiket& other) {
		this->x = other.x;
	}
	void test() {
		cout << "TEST\n";
	}
	void test2() {
	}
};

void test() {
	nachiket obj;
	obj.test();
	cout << obj.x << '\n';
}

int32_t main() {
	nachiket one;
	one.x = 22;
	nachiket two(one);
	cout << two.x << endl;
}
