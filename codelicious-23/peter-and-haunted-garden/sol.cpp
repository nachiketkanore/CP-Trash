/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 11:46:32 AM IST
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
	bool found = false;
	FOR(i, 1, N) {
		char ch;
		cin >> ch;
		if (ch == '_') {
			found = true;
			cout << i << " ";
		}
	}
	if (found) {
		cout << '\n';
	} else {
		cout << "-1\n";
	}
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
