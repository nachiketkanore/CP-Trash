/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 21 February 2024 11:21:52 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast16_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int N = 7;
int V[N], dp[N][1 << N][1 << N];
int cache[1 << N][1 << N][1 << N];

bool satisfies(int up, int mid, int down) {
	if (~cache[up][mid][down])
		return cache[up][mid][down];
	for (int bit = 1; bit < 6; bit++) {
		if ((mid >> bit & 1) && (up >> (bit - 1) & 1) && (up >> (bit + 1) & 1) && (down >> (bit - 1) & 1) && (down >> (bit + 1) & 1))
			return cache[up][mid][down] = false;
	}
	return cache[up][mid][down] = true;
}

int go(int id, int prev_mask, int prev_prev_mask) {
	if (id == N)
		return 0;
	int& ans = dp[id][prev_mask][prev_prev_mask];
	if (~ans)
		return ans;
	ans = 49;
	F0R(curr_mask, 1 << N) {
		if (satisfies(prev_prev_mask, prev_mask, curr_mask)) {
			int cost = __builtin_popcount(curr_mask ^ V[id]);
			ans = min(ans, int(cost + go(id + 1, curr_mask, prev_mask)));
			if (ans == 0)
				break;
		}
	}
	return ans;
}

void solve() {
	F0R(i, N) {
		string row;
		cin >> row;
		int mask = 0;
		F0R(j, N) if (row[j] == 'B') mask |= 1 << j;
		V[i] = mask;
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(cache, -1, sizeof(cache));

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
