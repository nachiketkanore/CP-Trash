/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 05:36:02 PM IST
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

int N, dp[50];
string S;

int go(int id) {
	if (id >= N)
		return 0;
	if (S[id] == '*')
		return -1e9;
	int coin = (S[id] == '@');
	int& ans = dp[id];
	if (~ans)
		return ans;
	ans = coin;
	ans = max(ans, coin + go(id + 1));
	ans = max(ans, coin + go(id + 2));
	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> S;
	cout << go(0) << '\n';
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
