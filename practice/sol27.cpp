#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 3e5 + 5, inf = 1e18;

int n, q, a[N], dp[2][N];

int go(int id, bool sign) {
	if (id == n + 1)
		return 0;
	int& ans = dp[sign][id];
	if (~ans) return ans;

	ans = go(id + 1, sign);
	ans = max(ans, (sign ? a[id] : -a[id]) + go(id + 1, !sign));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		cin >> n >> q;
		assert(!q);
		FOR(i,1,n) cin >> a[i], dp[0][i] = dp[1][i] = -1;
		cout << go(1, 1) << '\n';
	}
}