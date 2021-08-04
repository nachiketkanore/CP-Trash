#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1002, inf = 1e18;

int n, cost[N], has[N], dp[8][N];

int go(int id, int mask) {
	if (id == n + 1)
		return mask == 7 ? 0 : inf;
	int &ans = dp[mask][id];
	if (~ans)
		return ans;
	ans = go(id + 1, mask);
	ans = min(ans, cost[id] + go(id + 1, mask | has[id]));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i,1,n) {
		cin >> cost[i];
		string s;	cin >> s;
		for (char ch : s) 
			has[i] |= 1 << (ch - 'A');
	}
	memset(dp, -1, sizeof(dp));
	int ans = go(1,0);
	if (ans >= inf)
		ans = -1;
	cout << ans;
}