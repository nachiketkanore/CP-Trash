/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 03:07:21 PM IST
(ツ) If you are patient in one moment of anger, you will escape one hundred days of sorrow.
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

const int N = 1005, inf = 1e18;

int n, k;
int a[N];
int dp[N][N<<1];

int go(int id, int curr) {
	if (id == n+1)
		return curr;
	int &ans = dp[id][curr];
	if (~ans) return ans;
	ans = max(ans, go(id+1, curr));
	ans = max(ans, go(id+1, curr^a[id]));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		cin >> n >> k;
		FOR (i,1,n) { cin >> a[i]; }
		memset(dp, -1, sizeof(dp));
		cout << go(1,k) << "\n";
	}
}
