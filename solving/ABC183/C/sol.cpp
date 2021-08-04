/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:25:22 PM IST
(ツ) For everything that lives is holy, life delights in life.
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

int n, k, t[10][10];
int ans;

void go(int mask, int req, int prev) {
	if (__builtin_popcountll(mask) == n) {
		req += t[prev][0];
		if (req == k) ++ans;
		return;
	}

	for (int i = 0; i < n; i++) if ((mask >> i & 1) == 0) {
		go(mask | (1 << i), req + t[prev][i], i);
	}

}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	FOR (i,1,n) FOR (j,1,n) cin >> t[i-1][j-1];
	go(1,0,0);
	cout << ans;
}
