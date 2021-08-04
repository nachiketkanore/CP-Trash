/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 07:51:05 PM IST
(ツ) Learn all you can from the mistakes of others. You won't have time to make them all yourself.
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

const int N = 5000 + 5, inf = 1e18;

string A, B;
int n, m;
int dp[N][N];

int score(int i, int j) {
	if (i == n || j == m) return 0;
	int &ans = dp[i][j];
	if (~ans) return ans;
	ans = 0;

	if (A[i] == B[j]) {
		int get = 4 * (1) - (1) - (1);
		get += score(i + 1, j + 1);
		ans = max(ans, get);
	} else {
		int get = 4 * (0) - (1) - (0);
		get += score(i + 1, j);
		ans = max(ans, get);

		get = 4 * (0) - (0) - (1);
		get += score(i, j + 1);
		ans = max(ans, get);
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	cin >> A >> B;

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	FOR (i,0,n-1) FOR (j,0,m-1) ans = max(ans, score(i,j));
	cout << ans << "\n";
}
