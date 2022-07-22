/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 July 2022 04:05:38 PM IST
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
	int N, M;
	cin >> N >> M;
	pair<int, int> best = make_pair(N, N);
	FOR(g, N, min(M, 2 * N)) {
		int a = g;
		int b = g * (M / g);
		if (abs(best.first - best.second) < abs(a - b)) {
			best = make_pair(a, b);
		}
	}
	cout << best.first << ' ' << best.second << '\n';
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
