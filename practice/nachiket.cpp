#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, p, k;
int dp[N], a[N];

int go(int id) {
	if (id == 0) return 0;
	int &ans = dp[id];
	if (~ans) return ans;

	ans = inf;
	int c1 = a[id] + go(id - 1);
	int c2 = inf;

	int other_end = id - k + 1;
	if (other_end >= 1) {
		c2 = a[id] + go(other_end - 1);
	}
	ans = min(c1, c2);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		cin >> n >> p >> k;

		FOR(i,1,n) {
			cin >> a[i];
			dp[i] = -1;
		}

		sort (a + 1, a + n + 1);
		int ans = 0;
		
		FOR(i,1,n) {
			int minCost = go(i);
			if (minCost <= p) ans = max(ans, i);
		}
		cout << ans << '\n';
	}
}