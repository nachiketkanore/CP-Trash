#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 2e18;

int n, a[12], p[12], ans;
int dp[12][12][1 << 12];

int go(int prev2, int prev1, int mask) {
	int id = __builtin_popcountll(mask);
	if (id == n)
		return 0;
	int& ans = dp[prev2][prev1][mask];
	if (~ans)
		return ans;
	ans = inf;
	for (int i = 0; i < n; i++)
		if ((mask >> i & 1) == 0) {
			int get = (a[prev2] ^ a[prev1] ^ a[i]) * p[id] + go(prev1, i, mask | (1 << i));
			ans = min(ans, get);
		}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ans = inf;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> p[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (i != j) {
					int get = go(i, j, (1 << i) | (1 << j));
					ans = min(ans, get);
				}
		}
		if (ans == inf)
			ans = 0;
		cout << ans << '\n';
	}
}