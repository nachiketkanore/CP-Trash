#include <iostream>
using namespace std;

struct school {
	static int id;
	school() {
		cout << ++id << '\n';
	}
};

int school::id = 0;

int main() {
	school schools[50];
}
