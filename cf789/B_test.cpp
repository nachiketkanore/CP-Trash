/**
 *    Author: Solve Machine
 *    Created: Sunday 08 May 2022 08:03:40 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int INF = 1e15;
int N, dp[2][2][200002];
string S;

int go(int id, int prev_cnt, int prev_val) {
	if (id == N) {
		if (prev_cnt % 2 == 0)
			return 0;
		return INF;
	}
	int& ans = dp[prev_cnt % 2][prev_val][id];
	if (~ans)
		return ans;
	ans = INF;

	// keep same
	{
		int put = S[id] - '0';
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, go(id + 1, prev_cnt + 1, put));
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, go(id + 1, 1, put));
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, go(id + 1, 1, put));
			}
		}
		ans = min({ ans, c1, c2 });
	}

	// change
	{
		int put = (S[id] - '0') ^ 1;
		int c1 = INF, c2 = INF;
		if (prev_val == put) {
			c1 = min(c1, 1 + go(id + 1, prev_cnt + 1, put));
			if (prev_cnt % 2 == 0) {
				c1 = min(c1, 1 + go(id + 1, 1, put));
			}
		} else {
			if (prev_cnt % 2 == 0) {
				c2 = min(c2, 1 + go(id + 1, 1, put));
			}
		}
		ans = min({ ans, c1, c2 });
	}

	return ans;
}

#include <chrono>
#include <random>

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve() {
	cin >> N >> S;
	F0R(i, 2) F0R(j, 2) F0R(k, N) dp[i][j][k] = -1;
	int ans = min(go(0, 0, 0), go(0, 0, 1));
	assert(ans <= N);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 100;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
