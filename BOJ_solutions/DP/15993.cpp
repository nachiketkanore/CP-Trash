#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 9;

int dp[N][2][2];
int n, m;

int go(int rem, int taken, int want) {
	if (rem < 0)
		return 0;
	if (rem == 0)
		return taken == want;
	int& ans = dp[rem][taken][want];
	if (~ans)
		return ans;
	ans = 0;
	FOR(v, 1, 3) ans = (ans + go(rem - v, (taken + 1) % 2, want)) % mod;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << go(n, 0, 1) << ' ' << go(n, 0, 0) << '\n';
	}
}