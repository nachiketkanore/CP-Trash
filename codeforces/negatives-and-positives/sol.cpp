/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 August 2023 08:37:58 PM IST
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

const int _ = 2e5, INF = 1e18;
bool vis[2][_];
int N, A[_], dp[2][_];

int go(int id, bool is_negated) {
	if (id == N)
		return 0;
	int& ans = dp[is_negated][id];
	if (vis[is_negated][id]) {
		return ans;
	}
	ans = -INF;
	vis[is_negated][id] = true;

	int curr = (is_negated ? -A[id] : A[id]);

	if (id + 1 < N) {
		ans = max(ans, -curr + go(id + 1, true));
	}
	ans = max(ans, curr + go(id + 1, false));

	return ans;
}

void solve() {
	cin >> N;
	F0R(i, N) {
		vis[0][i] = vis[1][i] = false;
		cin >> A[i];
	}
	cout << go(0, false) << '\n';
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
