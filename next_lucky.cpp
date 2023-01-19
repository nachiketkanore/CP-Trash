/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 04:26:04 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

string S;
int N;
int8_t dp[2][100];

bool go(int id, bool big) {
	if (id == N)
		return big;
	int8_t& ans = dp[big][id];
	if (~ans)
		return ans;
	ans = 0;
	int curr = S[id] - '0';
	int L = curr, R = 9;
	if (big)
		L = 0;
	FOR(put, L, R) {
		if (put == 3 || put == 5)
			ans |= go(id + 1, big || (put > curr));
	}
	return ans;
}

void trace(int id, bool big) {
	if (id == N) {
		assert(big);
		return;
	}
	bool ans = go(id, big);
	assert(ans);
	int curr = S[id] - '0';
	int L = curr, R = 9;
	if (big)
		L = 0;
	FOR(put, L, R) {
		if (put == 3 || put == 5)
			if (ans == go(id + 1, big || (put > curr))) {
				cout << put;
				return trace(id + 1, big || (put > curr));
			}
	}
	assert(false);
}

void solve() {
	cin >> S;
	memset(dp, -1, sizeof(dp));
	N = S.size();
	bool found = go(0, 0);
	if (found) {
		trace(0, 0);
		cout << '\n';
	} else {
		cout << string(N + 1, '3') << '\n';
	}
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
