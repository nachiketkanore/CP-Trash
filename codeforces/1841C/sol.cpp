/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 13 September 2023 07:52:21 PM IST
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

string S;
const int INF = 1e18;
int dp[2][5][200000];

int power10(int times) {
	int result = 1;
	while (times--) {
		result *= 10;
	}
	return result;
}

int go(int id, int changed, int max_right) {
	if (changed > 1)
		return -INF;
	if (id == -1) {
		return 0;
	}

	const int curr = S[id] - 'A';
	int& ans = dp[changed][max_right][id];
	if (~ans)
		return ans;
	ans = -INF;

	F0R(put, 5) {
		int val = power10(put);
		if (put < max_right) {
			val = -val;
		}
		int get = val + go(id - 1, changed + (put != curr), max(max_right, put));
		ans = max(ans, get);
	}

	return ans;
}

void solve() {
	cin >> S;
	const int N = S.size();
	F0R(i, 2) F0R(j, 5) F0R(k, N) dp[i][j][k] = -1;
	cout << go(N - 1, 0, 0) << '\n';
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
