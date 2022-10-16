/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 08:05:43 PM IST
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
	int a[n];
	F0R(i, n) cin >> a[i];
	string s;
	cin >> s;
	map<int, set<char>> f;
	F0R(i, n) {
		f[a[i]].insert(s[i]);
	}
	for (auto [k, v] : f) {
		if (sz(v) > 1) {
			cout << "NO\n";
			return;
		}
	}
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
