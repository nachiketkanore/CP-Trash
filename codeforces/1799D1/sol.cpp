/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 14 February 2024 12:46:14 AM IST
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

const int MAX_N = 5005;
const int INF = 1e18;
int N, K, A[MAX_N], cold[MAX_N], hot[MAX_N];
int dp[MAX_N][MAX_N];

int go(int id, int id1, int id2) {
	if (id == N + 1)
		return 0;
	int& ans = dp[id][min(id1, id2)];
	if (~ans)
		return ans;
	ans = INF;

	// give to 1
	int c1;
	if (A[id1] == A[id]) {
		c1 = hot[A[id]] + go(id + 1, id, id2);
	} else {
		c1 = cold[A[id]] + go(id + 1, id, id2);
	}
	ans = min(ans, c1);
	// give to 2
	int c2;
	if (A[id2] == A[id]) {
		c2 = hot[A[id]] + go(id + 1, id1, id);
	} else {
		c2 = cold[A[id]] + go(id + 1, id1, id);
	}
	ans = min(ans, c2);

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> N >> K;
		F0R(i, N + 1) F0R(j, N + 1) dp[i][j] = -1;
		FOR(i, 1, N) cin >> A[i];
		FOR(i, 1, K) cin >> cold[i];
		FOR(i, 1, K) cin >> hot[i];
		cout << go(1, 0, 0) << '\n';
	}

	return 0;
}
