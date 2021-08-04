/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 05:19:08 PM IST
(ツ) Truth is generally the best vindication against slander.
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

const int N = 1e5 + 5, mod = 1e9 + 7;

int n;
int dp[3][3][3][3][3][N];

int go(int id, int prefSum, int cntPref0, int cntPref1, int cntPref2, int totCnt) {
	if (id == n + 1) {
		return totCnt && (totCnt % 3 == 0);
	}
	// int &ans = dp[prefSum % 3][cntPref0 % 3][cntPref1 % 3][cntPref2 % 3][totCnt % 3][id % 3];
	// if (~ans) return ans;
	int ans = 0;

	FOR(dig,0,9) {

		int next_prefSum = (prefSum + dig);

		int wantMod = (3 - (next_prefSum % 3)) % 3;
		int ansAdd = 0;

		if (wantMod == 0) ansAdd = cntPref0;
		else if (wantMod == 1) ansAdd = cntPref1;
		else if (wantMod == 2) ansAdd = cntPref2;
		else assert(false);

		int next_cntPref0 = cntPref0 + (next_prefSum % 3 == 0);
		int next_cntPref1 = cntPref1 + (next_prefSum % 3 == 1);
		int next_cntPref2 = cntPref2 + (next_prefSum % 3 == 2);

		int next_totCnt = totCnt + ansAdd;

		int get = go(id + 1, next_prefSum, next_cntPref0, next_cntPref1, next_cntPref2, next_totCnt);
		ans = (ans + get) % mod;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	n = 2;
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	FOR(dig,1,9) {
		int get = go(2, dig, 1 + (dig % 3 == 0), dig % 3 == 1, dig % 3 == 2, dig % 3 == 0);
		ans = (ans + get) % mod;
	}
	cout << ans << '\n';
}
