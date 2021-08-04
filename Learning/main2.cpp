#include <iostream>
using namespace std;

int* test() {
	int val = 21;
	val = 222;
	val++;
	return &val;
	// compiler throws warning for this one 
}

// works different with static variables
// static variables are stored in global memory
int* test2() {
	static int val = 1000;
	return &val;
	// no compile warning for this
}

class A                     { public: int val = 21; void eat(){ cout<<"A\n";} }; 
class B: virtual public A   { public: void eat(){ cout<<"B\n";} }; 
class C: virtual public A   { public: void eat(){ cout<<"C\n";} }; 
class D: public         B,C { public: void eat(){ cout << val << endl;} }; 

int32_t main() {
    A *a = new D(); 
    a->eat(); 
	cout << a->val << endl;
	return 0;


	int* ptr;
	int val = 21;
	ptr = &val;
	cout << *ptr << endl;
	ptr = test2();
	cout << *ptr << endl;
	ptr = test();
	// now ptr is a dangling pointer
	// because it points to variable which is deleted
	cout << ptr << endl;
	try {
		if (ptr == nullptr) throw "dangling pointer\n";
		cout << *ptr << endl;
	} catch (const char *error) {
		cout << "FOUND ERROR: ";
		cout << error << endl;
	}
}

