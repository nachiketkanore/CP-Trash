/** - my approach was correct, must be some error in the implementation
 *  - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 10:47:48 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int lsb(int val) {
	F0R(bit, 30) if (val >> bit & 1) return bit;
	return -1;
}

void solve() {
	int a, b;
	cin >> a >> b;

	bool ok = a <= b;

	while (b > 0) {
		int a_lsb = lsb(a), b_lsb = lsb(b);
		if (a == 0 || a_lsb > b_lsb) {
			ok = false;
		}
		a -= 1 << a_lsb;
		b -= 1 << b_lsb;
	}

	cout << (ok ? "YES\n" : "NO\n");
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
