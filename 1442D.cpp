/**
 *    Author: Nachiket Kanore
 *    Created: Monday 25 April 2022 09:59:52 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1e6 + 6;
const int INF = 1e17;
int N, K, T[_], dp[3003][3003];

/* int go(int id, int rem) {
	if (rem < 0)
		return -INF;
	if (rem == 0)
		return 0;
	if (id == N + 1)
		return rem == 0 ? 0 : -INF;
	int& ans = dp[id][rem];
	if (~ans)
		return ans;
	ans = -INF;
	F0R(take, T[id] + 1) {
		ans = max(ans, mat[id][take] + go(id + 1, rem - take));
	}
	return ans;
} */

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	vector<int> dp(K + 1);
	F0R(i, N) {
		int t;
		cin >> t;
		vector<int> A(t + 1);
		FOR(j, 1, t) {
			cin >> A[j];
			A[j] += A[j - 1];
		}
		vector<int> ndp(K + 1);
		F0R(j, K + 1) {
			FOR(take, 0, t) {
				if (j - take >= 0 && j - take <= K)
					ndp[j] = max(ndp[j], dp[j - take] + A[take]);
			}
		}
		dp = ndp;
	}
	cout << dp[K] << '\n';
	return 0;
}
