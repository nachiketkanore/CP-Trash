/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 04:40:48 PM IST
(ツ) Miracles come in moments. Be ready and willing.
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

const int N = 1e6 + 5, mod = 1e9 + 7;

int n, a[N], dp[3][2][N];

int go(int id, int prev, int nz) {
	if (id == n + 1)
		return nz;
	int &ans = dp[prev][nz][id];
	if (~ans) return ans;
	ans = 0;
	if (prev == 2) {
		ans = (ans + go(id + 1, a[id], 1)) % mod;
		ans = (ans + go(id + 1, 2, nz)) % mod;
	} else {
		if (prev != a[id]) 
			ans = (ans + go(id + 1, a[id], 1)) % mod;
		ans = (ans + go(id + 1, prev, nz)) % mod;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) a[i] = i&1;
	memset(dp, -1, sizeof(dp));
	cout << go(1,2,0);
}
