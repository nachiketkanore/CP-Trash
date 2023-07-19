/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 19 July 2023 10:38:48 PM IST
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

const int MX = 2e3 + 5, INF = 1e18;
int N, K, A[MX], dp[2][MX][2 * MX];
bool vis[2][MX][2 * MX];

int go(int id, bool neg, int ops_rem) {
	if (ops_rem < 0) {
		return -INF;
	}
	if (id > N) {
		return (ops_rem == 0 ? 0 : -INF);
	}
	bool& check = vis[neg][id][ops_rem];
	int& ans = dp[neg][id][ops_rem];
	if (check)
		return ans;
	check = true;
	ans = -INF;

	int curr = A[id] * (neg ? -1 : 1);

	if (id + 1 <= N) {
		// negate (curr, A[id + 1]) -> (-curr, -A[id + 1])
		int c1 = -curr + go(id + 1, true, ops_rem - 1);
		ans = max(ans, c1);
		// dont negate (curr, A[id + 1]) -> (curr, A[id + 1])
		int c2 = curr + go(id + 1, false, ops_rem);
		ans = max(ans, c2);
	} else {
		ans = max(ans, curr);
	}

	return ans;
}

void solve() {
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
		F0R(j, 2 * N + 1) F0R(k, 2) vis[k][i][j] = false;
	}
	int lo = 0, hi = 2 * N;
	int best = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int max_value = go(1, false, mid);
		if (max_value >= K) {
			best = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << best << '\n';
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
