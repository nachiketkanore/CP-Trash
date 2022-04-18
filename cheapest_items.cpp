/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 11:49:24 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _	  = 1005;
const int INF = 1e17;
int N, V[_], P[_], dp[_][_];

int go(int id, int sum) {
	if (sum >= N)
		sum = N;
	if (id == N) {
		return sum >= N ? 0 : INF;
	}
	int& ans = dp[id][sum];
	if (~ans)
		return ans;
	ans = INF;
	ans = min(ans, P[id] + go(id + 1, sum + 1 + V[id]));
	ans = min(ans, go(id + 1, sum));
	return ans;
}

void solve() {
	cin >> N;
	F0R(i, N) {
		cin >> V[i] >> P[i];
		F0R(j, N + 1) dp[i][j] = -1;
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
