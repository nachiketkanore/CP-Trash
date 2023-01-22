#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 1e3 + 5, mod = 1e9 + 9;

int dp[N][N];
int n, m;

int go(int rem, int taken) {
	if (taken < 0 || rem < 0)
		return 0;
	if (rem == 0)
		return taken == 0;
	int& ans = dp[rem][taken];
	if (~ans)
		return ans;
	ans = 0;
	FOR(v, 1, 3) ans = (ans + go(rem - v, taken - 1)) % mod;
	return ans;
}

void test() {
	int u, v;
	cin >> u >> v;
	return max(u, v);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << go(n, m) << '\n';
	}
}