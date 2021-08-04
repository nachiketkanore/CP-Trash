/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 02:55:48 PM IST
(ツ) I believe in one thing only, the power of human will.
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

const int N = 2e5 + 5, inf = 1e18;

string s;
int n;
int dp[20][3][20];

int go(int id, int sumMod, int del) {
	if (del > n-1) return inf;
	if (id == n)
		return (sumMod == 0 ? 0 : inf);

	int &ans = dp[id][sumMod][del];
	if (~ans) return ans;

	ans = 1 + go(id + 1, sumMod, del + 1);	// delete s[id]
	ans = min(ans, go(id + 1, (sumMod + (s[id]-'0')) % 3, del));

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = sz(s);
	memset(dp, -1, sizeof(dp));
	int ans = go(0,0,0);
	if (ans >= inf) cout << "-1";
	else cout << ans;
}
