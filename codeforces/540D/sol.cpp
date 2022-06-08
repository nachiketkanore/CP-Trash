/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 June 2022 07:15:41 PM IST
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

int r, p, s;
vector<pair<int, int>> killers;
const double EPS = 1e-7;
double dp[3][101][101][101];
bool vis[3][101][101][101];

double go(int R, int P, int S, int winner) {
	int A[3];
	A[0] = R, A[1] = P, A[2] = S;

	if (A[winner] == 0)
		return 0;

	if (vis[winner][R][P][S])
		return dp[winner][R][P][S];
	vis[winner][R][P][S] = true;
	double& ans = dp[winner][R][P][S];
	ans = 0;

	bool end = true;
	F0R(i, 3) {
		if (i == winner)
			end &= A[i] > 0;
		else
			end &= A[i] == 0;
		assert(A[i] >= 0);
	}

	if (end) {
		return 1;
	}

	int tot = 0;
	F0R(i, 3) F0R(j, i) tot += A[i] * A[j];

	for (auto [first, second] : killers) {
		if (A[first] && A[second]) {
			int B[3];
			int choices = A[first] * A[second];
			B[0] = A[0], B[1] = A[1], B[2] = A[2];
			B[second]--;
			ans += (1. * choices / tot) * go(B[0], B[1], B[2], winner);
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(vis, false, sizeof(vis));
	int R, S, P;
	cin >> R >> S >> P;
	r = 0, p = 1, s = 2;
	killers = { pair<int, int>(0, 2), pair<int, int>(2, 1), pair<int, int>(1, 0) };

	for (int winner : { 0, 2, 1 })
		cout << fixed << setprecision(12) << go(R, P, S, winner) << " \n"[winner == 1];

	return 0;
}
