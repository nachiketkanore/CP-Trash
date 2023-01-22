/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:35:48 PM IST
(ツ) We do not quit playing because we grow old, we grow old because we quit playing.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;

int pref[N + 1];

int digs(int n) {
	return (n == 0 ? 0 : 1 + digs(n / 10));
}

int cnt(int n, int d) {
	int ret = 0;
	while (n) {
		ret += (n % 10) == d;
		n /= 10;
	}
	return ret;
}

bool ok(int n) {
	int d = digs(n);
	bool OK = true;
	FOR(i, 1, d) OK &= cnt(n, i) == 1;
	return OK;
}

void pre() {
	FOR(i, 1, N) {
		pref[i] = ok(i) + pref[i - 1];
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pre();
	int T;
	cin >> T;
	while (T--) {
		int L, R;
		cin >> L >> R;
		cout << (pref[R] - pref[L - 1]) << "\n";
	}
}
