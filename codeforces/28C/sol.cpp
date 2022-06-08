/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 June 2022 02:09:58 PM IST
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

const int MAX = 50;
int N, M, A[55], C[MAX + 1][MAX + 1];

bool vis[55][55][100];
double dp[55][55][100];

double go(int rem, int id, int largest) {
	if (id == M + 1) {
		if (rem != 0)
			return 0;
		return largest;
	}

	if (vis[rem][id][largest])
		return dp[rem][id][largest];

	vis[rem][id][largest] = true;

	double& ans = dp[rem][id][largest];
	ans = 0;

	FOR(put, 0, rem) {
		int ways = C[rem][put];
		int len = (put + A[id] - 1) / A[id];
		int new_largest = max(largest, len);
		ans += 1. * ways * go(rem - put, id + 1, new_largest);
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(i, 0, MAX) C[i][0] = 1, C[i][i] = 1;
	FOR(i, 1, MAX) FOR(j, 1, i) C[i][j] = (j ? C[i - 1][j - 1] : 0) + C[i - 1][j];

	memset(vis, false, sizeof(vis));
	cin >> N >> M;
	FOR(i, 1, M) cin >> A[i];
	cout << fixed << setprecision(15) << 1. * go(N, 1, 0) / pow(M, N) << '\n';

	return 0;
}
