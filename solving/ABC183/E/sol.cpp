/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:25:22 PM IST
(ツ) If the stars should appear but one night every thousand years how man would marvel and adore.
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

const int N = 2000 + 5, mod = 1e9 + 7;

int n, m, mat[N][N], dp[N][N], dpLeft[N][N], dpDiag[N][N], dpUp[N][N];

void add(int &a, int b) {
	a = (a + b) % mod;
}

bool inside(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int getLeft(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dpLeft[i][j];
	if (~ans) return ans;
	int ret = dp[i][j] + getLeft(i, j-1);
	ret %= mod;
	return ans = ret;
}


int getUp(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dpUp[i][j];
	if (~ans) return ans;
	int ret = dp[i][j] + getUp(i-1, j);
	ret %= mod;
	return ans = ret;
}


int getDiag(int i, int j) {
	if (!inside(i, j)) return 0;
	if (!mat[i][j]) return 0;
	int &ans = dpDiag[i][j];
	if (~ans) return ans;
	int ret = dp[i][j] + getDiag(i-1, j-1);
	ret %= mod;
	return ans = ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	FOR (i,1,n) FOR (j,1,m) {
		char ch;	cin >> ch;
		if (ch == '.')
			mat[i][j] = 1;
		else mat[i][j] = 0;
	}


	memset(dpLeft, -1, sizeof(dpLeft));
	memset(dpUp, -1, sizeof(dpUp));
	memset(dpDiag, -1, sizeof(dpDiag));

	dp[1][1] = 1;

	FOR (col,2,m) {
		if (mat[1][col]) {
			dp[1][col] = getLeft(1,col-1);
		}
	}

	FOR (row,2,n) {
		if (mat[row][1]) {
			dp[row][1] = getUp(row-1,1);
		}
	}
	FOR (i,2,n) FOR (j,2,m) {
		if (mat[i][j]) {
			dp[i][j] += getDiag(i-1,j-1);
			dp[i][j] %= mod;		
			dp[i][j] += getLeft(i,j-1);
			dp[i][j] %= mod;
			dp[i][j] += getUp(i-1,j);
			dp[i][j] %= mod;
		}
	}

	cout << dp[n][m] << "\n";
}
