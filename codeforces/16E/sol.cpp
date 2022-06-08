/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 June 2022 06:58:23 PM IST
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

const int _ = 18;
int N;
double prob[_][_];
bool vis[_][1 << _];
double dp[_][1 << _];

double go(int last, int dead) {
	if (dead >> last & 1)
		return 0;
	int want = ((1 << N) - 1) ^ (1 << last);
	if (dead == want)
		return 1;

	if (vis[last][dead])
		return dp[last][dead];
	vis[last][dead] = true;

	double& ans = dp[last][dead];
	ans = 0;

	double lose_prob[N];
	int tot = 0;
	fill(lose_prob, lose_prob + N, 0.);

	F0R(i, N) if ((dead >> i & 1) == 0) {
		F0R(j, i) if ((dead >> j & 1) == 0) {
			lose_prob[i] += prob[j][i];
			lose_prob[j] += prob[i][j];
			tot++;
		}
	}

	assert(tot > 0);
	// choose who loses in this turn
	F0R(i, N) if ((dead >> i & 1) == 0) {
		ans += lose_prob[i] * go(last, dead | (1 << i));
	}
	ans /= tot;

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) F0R(j, N) cin >> prob[i][j];
	F0R(i, N) cout << fixed << setprecision(6) << go(i, 0) << " \n"[i == N - 1];

	return 0;
}
