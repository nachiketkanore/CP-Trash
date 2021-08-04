/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:25:22 PM IST
(ツ) One secret of success in life is for a man to be ready for his opportunity when it comes.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;

	int num = sx * gy + gx * sy;
	int den = gy + sy;
	using ld = long double;
	ld ans = (ld)(num)/(ld)(den);
	cout << fixed << setprecision(10) << ans << "\n";
}
