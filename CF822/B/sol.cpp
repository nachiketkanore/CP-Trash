/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 September 2022 05:51:47 PM IST
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

vector<vector<int>> ans;

void solve() {
	int N; cin >> N;
	F0R (lvl, N) {
		for (int x: ans[lvl]) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans.push_back({1});
	FOR(len, 2, 505) {
		vector<int> put(len, 0);
		put[0] = put[len - 1] = 1;
		ans.push_back(put);
	}

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
