/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 11:53:41 AM IST
(ツ) Nothing is a waste of time if you use the experience wisely.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, a[N];
int dp[2][N];

int go(int id, bool T) {
	if (id > n) return (T? 0 : -inf);
	int &ans = dp[T][id];
	if (ans != -inf) return ans;
	ans = -inf;
	ans = max(ans, a[id] + go(id+2, 1));
	ans = max(ans, go(id+1, T));
	return ans;
}

void solve() {
	cin >> n;
	FOR (i,0,n+10) dp[0][i] = dp[1][i] = -inf;
	FOR (i,1,n) cin >> a[i];
	cout << go(1,0) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--)	solve();
}
