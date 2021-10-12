#include <iostream>
using namespace std;

#define int int64_t
#define see(x) cerr << #x << " = " << x << '\n'

class school {
public:
	// garbage `val`
	int val;
	~school() {
		cout << "Destucted\n";
	}
};

int T = 20;

void hello_world() {
	cout << "HELLO WORLD\n";
	return;
}

int32_t main() {
	for (int i = 0; i < 100; i++) {
		cout << i << endl;
	}
	int val = 21;
	see(val);
	school abc;
	cout << abc.val << endl;
}

