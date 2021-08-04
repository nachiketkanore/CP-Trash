/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 02:09:03 PM IST
(ツ) Friends are those rare people who ask how we are and then wait to hear the answer.
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

const int N = 130, inf = 1e18;
const int MOD = 1e9 + 9;

int k, b, len;
int dp[N][1000][N];

int go(int id, int mod, int taken) {
	if (id == len + 1) {
		return (mod == 0 ? taken : 0);
	}
	int &ans = dp[id][mod][taken];
	if (~ans) return ans;
	ans = 0;
	int c1 = go(id + 1, (mod * 2 + 0) % k, taken) % MOD;
	int c2 = go(id + 1, (mod * 2 + 1) % k, taken + 1) % MOD;
	ans = (c1 + c2) % MOD;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> k >> b;
	len = b;
	memset(dp, -1, sizeof(dp));
	int ans = go(1, 0, 0);
	cout << ans << '\n';
}
