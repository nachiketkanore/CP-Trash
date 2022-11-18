/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 08:05:21 PM IST
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
	string T;
	string S;
	cin >> S;
	while (sz(T) < sz(S) * 5)
		T += "Yes";
	const int N = S.size();
	F0R(i, sz(T)) {
		if (i + sz(S) - 1 >= sz(T))
			continue;
		if (T.substr(i, sz(S)) == S) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
