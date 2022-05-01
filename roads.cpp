/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 01 May 2022 03:46:30 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 505;
const int INF = 1e15;
int N, L, K, D[_], A[_], dp[_][_];
bool vis[_][_];

int go(int id, int rem) {
	if (rem < 0)
		return INF;
	if (id == N) {
		return (L - D[id]) * A[id];
	}
	if (vis[id][rem])
		return dp[id][rem];
	vis[id][rem] = true;
	int& ans = dp[id][rem];
	ans = INF;
	FOR(nxt, id + 1, N) {
		int skipped = nxt - id - 1;
		int req = (D[nxt] - D[id]) * A[id];
		ans = min(ans, req + go(nxt, rem - skipped));
	}
	int skipped = N - id;
	if (rem >= skipped) {
		ans = min(ans, (L - D[id]) * A[id]);
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(vis, false, sizeof(vis));
	cin >> N >> L >> K;
	FOR(i, 1, N) cin >> D[i];
	FOR(i, 1, N) cin >> A[i];
	cout << go(1, K) << '\n';
	return 0;
}
