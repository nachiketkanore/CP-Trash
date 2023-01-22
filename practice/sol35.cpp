#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int a, b, x, fa, fb, ga, gb;
map<array<int, 6>, int> dp;

int go(int rem, int cnta, int cntb, int rema, int remb, bool which) {
	if (rem < 0 || cnta < 0 || cntb < 0 || rema < 0 || remb < 0)
		return 0;
	if (rem == 0)
		return 1;
	if (dp.count({ which, rem, cnta, cntb, rema, remb }))
		return dp[{ which, rem, cnta, cntb, rema, remb }];
	int ans = 0;
	if (which) {
		FOR(take, 1, ga) {
			ans = (ans + go(rem - take, cnta - 1, cntb, rema - take, remb, which ^ 1)) % mod;
		}
	} else {
		FOR(take, 1, gb) {
			ans = (ans + go(rem - take, cnta, cntb - 1, rema, remb - take, which ^ 1)) % mod;
		}
	}
	dp[{ which, rem, cnta, cntb, rema, remb }] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		dp.clear();
		cin >> a >> b >> x;
		cin >> fa >> fb;
		cin >> ga >> gb;
		int ans = go(x, fa, fb, a, b, 0) + go(x, fa, fb, a, b, 1);
		ans %= mod;
		cout << ans << '\n';
	}
}