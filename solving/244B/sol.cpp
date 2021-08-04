/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 07:56:08 PM IST
(ツ) The way we communicate with others and with ourselves ultimately determines the quality of our lives.
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
int dp[11][1 << 10][2][2];

int go(int id, int mask, bool smallTaken, bool nonZeroTaken) {
	if (__builtin_popcountll(mask) > 2) return 0;
	if (id == sz(s)) 
		return 1;

	int &ans = dp[id][mask][smallTaken][nonZeroTaken];
	if (~ans) return ans;
	ans = 0;
	
	int curr = s[id] - '0';
	int from = -1, to = -1;
	if (smallTaken) {
		from = 0, to = 9;
	} else {
		from = 0, to = curr;
	}

	FOR(dig,from,to) {
		int nextMask = mask;
		if (nonZeroTaken || dig) nextMask |= (1 << dig);
		ans = ans + go(id + 1, nextMask, smallTaken || (dig < curr), nonZeroTaken || dig);
	}
	return ans;
}

int calc(int n) {
	s = to_string(n);
	memset(dp, -1, sizeof(dp));
	return go(0,0,0,0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;	cin >> n;
	cout << calc(n) - 1;	// remove 0
}
