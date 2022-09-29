/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 29 September 2022 08:07:08 PM IST
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

int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void solve() {
	int n, m;
	cin >> n >> m;
	FOR (i,1,n) {
		FOR (j,1,m) {
			bool ok = true;
			F0R (id,8) {
				int ni = i + X[id], nj = j + Y[id];
				ok &= !(ni >= 1 && ni <= n && nj >= 1 && nj <= m);
			}
			if (ok) {
				cout << i << ' ' << j << '\n';
				return;
			}
		}
	}
	cout << "1 1\n";
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
