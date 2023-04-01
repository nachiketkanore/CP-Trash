/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 01 April 2023 06:18:15 PM IST
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
	int n;
	cin >> n;
	bool ok = true;
	while (n > 0) {
		int dig = n % 16;
		if (dig > 9)
			ok = false;
		n /= 16;
	}
	if (ok)
		cout << "NO\n";
	else
		cout << "YES\n";
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
