/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 09:20:56 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 5e5 + 5;
const int INF = 1e15;
int N, A[_], dp[4][_];
bool vis[4][_];

int go(int id, int which) {
	if (which >= 4)
		return -INF;
	if (id == N) {
		return which == 3 ? 0 : -INF;
	}
	if (vis[which][id])
		return dp[which][id];
	int& ans = dp[which][id];
	ans = -INF;
	vis[which][id] = true;
	if (which == 0) {
		ans = max(ans, +A[id] + go(id + 1, 0));
		ans = max(ans, 0 + go(id + 1, 1));
	}
	if (which == 1) {
		ans = max(ans, -A[id] + go(id + 1, 1));
		ans = max(ans, 0 + go(id + 1, 2));
	}
	if (which == 2) {
		ans = max(ans, -A[id] + go(id + 1, 2));
		ans = max(ans, 0 + go(id + 1, 3));
	}
	if (which == 3) {
		ans = max(ans, +A[id] + go(id + 1, 3));
		// ans = max(ans, 0 + go(id + 1, 4));
	}
	return ans;
}

void solve() {
	cin >> N;
	F0R(i, N) {
		cin >> A[i];
		F0R(j, 4) vis[j][i] = false;
	}
	if (N <= 3) {
		cout << "0\n";
		return;
	}
	int ans = go(0, 0);
	cout << ans << '\n';
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
