/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 01 April 2023 05:32:04 PM IST
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
	string s;
	cin >> s;
	const int n = s.size();
	int a = 0, b = 0;
	F0R(i, n / 2) {
		a = a * 2 + (s[i] - '0');
	}
	FOR(j, n / 2, n - 1) {
		b = b * 2 + (s[j] - '0');
	}
	cout << __gcd(a, b) << '\n';
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
