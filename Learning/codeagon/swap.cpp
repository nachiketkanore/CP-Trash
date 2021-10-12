#include <iostream>

struct BIT {
	int N;
	int *bit;
	BIT(int N): N(N) { bit = new int[N+1]; }
	void upd(int id, int add) { for (; id <= N; id += id & -id) { bit[id] += add; } }
	int pref(int id) {
		int ret = 0; for (; id; id -= id & -id) { ret += bit[id]; }
		return ret;
	}
};

int main() {
	BIT bit(20);
	bit.pref(1);
	return 0;
}
