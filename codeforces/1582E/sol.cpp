/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 07:44:19 PM IST
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

const int MAX = 1e5 + 5;
const int INF = 1e18;
int N, A[MAX], dp[490][100002];
bool vis[490][100002];

int go(int id, int k) {
	if (k < 0)
		return -INF;
	if (id > N) {
		return k == 0 ? INF : -INF;
	}

	// [id id+1 id+2 .. id+k-1] .. [group] .. [group]
	if (vis[k][id])
		return dp[k][id];
	vis[k][id] = true;
	int& ans = dp[k][id];
	ans = -INF;
	if (id + k - 1 <= N) {
		int curr_sum = A[id + k - 1] - A[id - 1];
		if (curr_sum < go(id + k, k - 1)) {
			ans = max(ans, curr_sum);
		}
	}
	ans = max(ans, go(id + 1, k));

	return ans;
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	// k * (k + 1) / 2 <= N
	int answer = 0, K = 0;

	for (int k = 1; k * (k + 1) <= 2 * N; k++)
		K = k;

	// memset(vis, false, sizeof(vis));
	F0R(i, K + 1) F0R(j, N + 1) vis[i][j] = false;
	for (int k = K; k; --k) {
		if (go(1, k) != -INF) {
			cout << k << '\n';
			return;
		}
	}
	assert(false);
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
