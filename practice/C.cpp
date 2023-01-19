#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n;
bool likes[20][20];
int dp[20][1 << 20];

int go(int id, int done) {
	if (id == n) {
		assert(__builtin_popcountll(done) == n);
		return 1;
	}
	int& ans = dp[id][done];
	if (~ans)
		return ans;
	ans = 0;
	for (int topic = 0; topic < n; topic++)
		if (likes[id][topic] && ((done >> topic & 1) == 0)) {
			ans = (ans + go(id + 1, done | (1 << topic))) % mod;
		}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> likes[i][j];
		}
		for (int mask = 0; mask < (1 << n); mask++)
			dp[i][mask] = -1;
	}
	int ans = go(0, 0);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}