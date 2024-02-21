/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 05:49:03 PM IST
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

void solve() {
	int N;
	cin >> N;
	int curr = 1;
	F0R(i, N) {
		int x;
		cin >> x;
		int k = (curr % x == 0 ? curr / x + 1 : (curr + x - 1) / x);
		if (i == 0 && x == 1)
			k = 1;
		curr = x * k;
	}
	cout << curr << '\n';
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
