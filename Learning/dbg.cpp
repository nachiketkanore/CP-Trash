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

int32_t main() {
	int val = 21;
	see(val);
	school abc;
	cout << abc.val << endl;
}

