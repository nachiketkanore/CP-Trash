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

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 2e3 + 5;
const int INF = 1e18;
int N, M, K, A[_], offer[_];
int dp[_][_];

int go(int id, int rem) {
	if (rem == 0)
		return 0;
	if (id == N + 1)
		return INF;

	int& ans = dp[rem][id];
	if (~ans)
		return ans;
	ans = INF;
	ans = min(ans, go(id + 1, rem));

	FOR(take, 1, rem) {
		if (id + take - 1 > N)
			break;
		int cost = A[id + take - 1] - A[id - 1];
		if (offer[take] > 0) {
			cost -= A[id + offer[take] - 1] - A[id - 1];
		}
		ans = min(ans, cost + go(id + take, rem - take));
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// not optimal
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, M) {
		int x, y;
		cin >> x >> y;
		offer[x] = max(offer[x], y);
	}

	sort(A + 1, A + N + 1);
	FOR(i, 1, N) A[i] += A[i - 1];

	int ans = go(1, K);
	cout << ans << '\n';
	return 0;
}
