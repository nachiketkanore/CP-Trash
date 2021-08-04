/*
Author: Nachiket Kanore
Created: Thursday 03 December 2020 12:21:57 AM IST
(ツ) Faith in oneself is the best and safest course.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2000 + 5, inf = 1e18;

int n, m;
bool mat[N][N];
int dp[4][N][N];

bool inside(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int goLeft(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dp[0][i][j];
	if (~ans) return ans;
	ans = 1 + goLeft(i,j-1);
	return ans;
}

int goRight(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dp[1][i][j];
	if (~ans) return ans;
	ans = 1 + goRight(i,j+1);
	return ans;
}

int goUp(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dp[2][i][j];
	if (~ans) return ans;
	ans = 1 + goUp(i-1,j);
	return ans;
}

int goDown(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dp[3][i][j];
	if (~ans) return ans;
	ans = 1 + goDown(i+1,j);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FOR (i,1,n) FOR (j,1,m) {
		char ch;	cin >> ch;
		mat[i][j] = ch == '.';
	}

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	FOR (i,1,n) FOR (j,1,m) 
		if (mat[i][j]) 
			ans = max(ans, 1+goLeft(i,j-1)+goRight(i,j+1)+goUp(i-1,j)+goDown(i+1,j));
	cout << ans;
}
