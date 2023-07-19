/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 19 July 2023 09:52:04 PM IST
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

const int MAX = 1e4;
int n, x, A[MAX], dp[2][MAX];

int go(int id, bool prev_applied) {
	if (id == n)
		return 0;
	int& ans = dp[prev_applied][id];
	if (~ans)
		return ans;
	ans = 0;
	int c1 = abs(A[id] - (A[id - 1] ^ (prev_applied ? x : 0))) + go(id + 1, false);
	int c2 = abs((A[id] ^ x) - (A[id - 1] ^ (prev_applied ? x : 0))) + go(id + 1, true);
	return ans = max(c1, c2);
}

void solve() {
	cin >> n >> x;
	F0R(i, n) {
		cin >> A[i];
		dp[0][i] = dp[1][i] = -1;
	}
	cout << max(go(1, false), go(1, true)) << '\n';
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
