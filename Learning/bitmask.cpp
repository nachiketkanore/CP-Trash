/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 03 October 2021 11:08:08 AM IST
**/
#include <bits/stdc++.h>

#define int int64_t
#define F0R(i,R) for(int i = (0); i < (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int INF = 1e18;
int C, B;
int cost[10][20];
int dp[20][1 << 10];

int go(int cid, int bmask) {
	if (cid == C) return 0;
	int &ans = dp[cid][bmask];
	if (~ans) return ans;
	ans = INF;

	// assign some banker (unset in bmask) to some [cid, j] where j < C
	
	F0R (who,B) {
		if (bmask >> who & 1) continue;
		int req = 0;
		for (int ncid = cid; ncid < C; ncid++) {
			req += cost[who][ncid];
			cmin(ans, req + go(ncid + 1, bmask | (1 << who)));
		}
	}

	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> C >> B;
	F0R (i,B) { F0R (j,C) cin >> cost[i][j]; }
	int ans = go(0, 0);
	cout << ans;
}
