/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 April 2022 04:49:28 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int INF = 1e18;
const int _ = 405;
int N, D, A[_];
int dp[2][_][_];

int get_cost(int to, int from) {
	if (to == from)
		return 0;
	int best = INF;
	if (from <= to) {
		best = min(best, to - from);
		best = min(best, D - to + from);
	} else {
		best = min(best, from - to);
		best = min(best, D - from + to);
	}
	assert(best ^ INF);
	return best;
}

int go(int L, int R, bool left) {
	int val = left ? A[L] : A[R];
	if (L == 1 && R == N)
		return get_cost(0, val);
	int& ans = dp[left][L][R];
	if (~ans)
		return ans;
	ans = INF;
	if (L - 1 >= 1) {
		int here = A[L - 1];
		int cost = get_cost(here, val);
		ans = min(ans, cost + go(L - 1, R, true));
	}
	if (R + 1 <= N) {
		int here = A[R + 1];
		int cost = get_cost(here, val);
		ans = min(ans, cost + go(L, R + 1, false));
	}
	assert(ans ^ INF);
	return ans;
}

void solve() {
	cin >> N >> D;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	int ans = INF;
	memset(dp, -1, sizeof(dp));
	FOR(i, 1, N) {
		ans = min(ans, go(i, i, 0));
		ans = min(ans, go(i, i, 1));
	}
	assert(ans ^ INF);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
