/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 08:03:50 PM IST
(ツ) Always bear in mind that your own resolution to succeed is more important than any one thing.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 200 + 5, inf = 1e18;

int n, t[N], dp[N][N * N + N];

int go(int id, int curr) {
	if (id == n + 1)
		return 0;
	if (curr > n * n) return inf;

	int &ans = dp[id][curr];
	if (~ans)
		return ans;
	ans = inf;

	int c1 = abs(curr - t[id]) + go(id + 1, curr + 1);
	int c2 = go(id, curr + 1);

	ans = min(c1, c2);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR (i,1,n) cin >> t[i];
		FOR (i,1,n) FOR(j,1,n*n) dp[i][j] = -1;
		sort (t + 1, t + n + 1);
		int ans = go(1, 1);
		cout << ans << '\n';
	}
}
