/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 27 June 2023 11:24:19 PM IST
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

const int _ = 1e5 + 5, INF = 1e18;
int b[_], N, dp[4][_];
bool vis[4][_];

int go(int id, int gid) {
	if (gid > 3)
		return -INF;
	if (id > N) {
		if (gid == 3)
			return 0;
		return -INF;
	}

	if (vis[gid][id])
		return dp[gid][id];

	int ans = -INF;
	ans = max(ans, go(id + 1, gid));

	if (gid == 0) {
		int get = id + b[id] + go(id + 1, gid + 1);
		ans = max(ans, get);
	} else if (gid == 1) {
		int get = b[id] + go(id + 1, gid + 1);
		ans = max(ans, get);
	} else if (gid == 2) {
		int get = -id + b[id] + go(id + 1, gid + 1);
		ans = max(ans, get);
	}

	vis[gid][id] = true;
	dp[gid][id] = ans;

	return ans;
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		F0R(j, 4) vis[j][i] = false;
		cin >> b[i];
	}
	cout << go(1, 0) << '\n';
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
