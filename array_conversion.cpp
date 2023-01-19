/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 04:58:31 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 100;
const int OFFSET = 2e4;
int N, K, A[_];
int8_t dp[_][2 * OFFSET];

bool go(int id, int sum) {
	if (id == N) {
		return sum == K;
	}
	int8_t& ans = dp[id][sum + OFFSET];
	if (~ans)
		return ans;
	ans = 0;
	ans |= go(id + 1, sum + A[id]);
	ans |= go(id + 1, sum - A[id]);
	ans |= go(id + 1, sum + A[id] + id + 1);
	ans |= go(id + 1, sum + A[id] - (id + 1));
	return ans;
}

void solve() {
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	F0R(i, N) cin >> A[i];
	cout << (go(0, 0) ? "YES\n" : "NO\n");
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
