#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

array<int,3> env[5005];
int n, W, H;
int dp[5005];

bool yes(int id) {
	return W < env[id][0] && H < env[id][1];
}

bool yes(int i, int j) {
	assert(i < j);
	return env[i][0] < env[j][0] && env[i][1] < env[j][1];
}

int go(int from) {
	if (from > n)
		return 0;
	int& ans = dp[from];
	if (~ans)
		return ans;
	ans = 0;

	FOR(to,from+1,n) if (yes(to) && yes(from, to)) {
		ans = max(ans, 1 + go(to));
	}
	return ans;
}

void trace(int from) {
	if (from > n)
		return ;
	int ans = go(from);

	FOR(to,from+1,n) if (yes(to) && yes(from, to)) {
		if (1 + go(to) == ans) {
			cout << env[to][2] << ' ';
			return trace(to);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> W >> H;
	FOR(i,1,n) {
		cin >> env[i][0] >> env[i][1];
		env[i][2] = i;
	}	
	
	memset(dp, -1, sizeof(dp));
	sort (env + 1, env + n + 1);
	int ans = 0;

	FOR(i,1,n) if (yes(i)) ans = max(ans, 1 + go(i));
	cout << ans << '\n';
	FOR(i,1,n) if (yes(i) && ans == 1 + go(i)) {
		cout << env[i][2] << ' ';
		trace(i);
		return 0;
	}
}