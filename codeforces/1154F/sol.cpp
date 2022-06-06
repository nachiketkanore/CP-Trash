/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 June 2022 11:50:21 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 2e5 + 5;
const int INF = 1e18;
int N, M, K, A[_], offer[_], x, y;
int dp[2001];

int go(int id) {
	if (id == N + 1)
		return 0;

	int& ans = dp[id];
	if (~ans)
		return ans;
	ans = INF;

	FOR(k, 1, K) {
		int j = id + k - 1;
		if (j <= N) {
			int cost = A[j] - A[id + offer[k] - 1];
			ans = min(ans, cost + go(id + k));
		}
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, M) {
		cin >> x >> y;
		offer[x] = max(offer[x], y);
	}

	sort(A + 1, A + N + 1);
	FOR(i, 1, N) A[i] += A[i - 1];

	N = min(N, K);
	memset(dp, -1, sizeof(dp));
	/* F0R(i, N + 1) dp[i] = INF;
	dp[0] = 0;
	FOR(i, 1, N) {
		FOR(k, 1, K) {
			int j = i - k + 1;
			if (j < 0 || i - k < 0)
				continue;
			// choose A[j, i]
			int cost = A[i] - A[j + offer[k] - 1];
			dp[i] = min(dp[i], cost + dp[i - k]);
		}
	} */
	// cout << dp[N] << '\n';

	cout << go(1) << '\n';
	return 0;
}
