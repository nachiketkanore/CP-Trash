/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:49:59 PM IST
(ツ) Genuine sincerity opens people's hearts, while manipulation causes them to close.
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

const int N = 3e5 + 5, inf = 1e18;

int n, a[N];

int getMin(int L, int R) {
	assert(L <= R);
	int ret = a[L];
	FOR (i,L,R) ret = min(ret, a[i]);
	return ret;
}

int getMax(int L, int R) {
	assert(L <= R);
	int ret = a[L];
	FOR (i,L,R) ret = max(ret, a[i]);
	return ret;
}

void solve() {
	cin >> n;
	FOR (i,1,n) cin >> a[i];
	int pmax = 0;
	FOR (i,1,n) {
		pmax = max(pmax, a[i]);
		// prefix max_s increase from left to right
		// suffix max_s increase from right to left
		// find the first valid border for middle part
		// middle part behaves like this
		// >pmax >pmax ... =pmax =pmax ... <pmax <pmax ..<
		//                 ^ finding this position

		int lo = i+1, hi = n-1;
		int best = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (getMin)
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--) solve();
}
