/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 05:03:38 PM IST
(ツ) Trusting our intuition often saves us from disaster.
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

const int N = 1e6 + 5, inf = 1e18;

int n, last[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	using ld = long double;
	ld ans = 0.0, get = 0.0;
	cin >> n;
	FOR (i,1,n) {
		int val;
		cin >> val;
		get += (i - last[val]);
		ans += 2 * get - 1;
		last[val] = i;
	}
	ans /= (ld) n*n;
	printf("%0.10Lf", ans);
}
