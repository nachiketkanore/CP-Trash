/**
 *    Author: Nachiket Kanore
 *    Created: Monday 25 April 2022 09:59:52 PM IST
 **/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1e6 + 6;
int N, K, T[_], val;
int64_t dp[3001], ndp[3001];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	F0R(i, N) {
		F0R(j, K + 1) ndp[j] = dp[j];
		int64_t pref = 0;
		int t;
		cin >> t;
		FOR(j, 1, t) {
			cin >> val;
			pref += val;
			FOR(tot, j, K) {
				ndp[tot] = max(ndp[tot], dp[tot - j] + pref);
			}
		}
		F0R(j, K + 1) dp[j] = ndp[j];
	}
	cout << dp[K] << '\n';
	return 0;
}
