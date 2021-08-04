/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 03:34:55 PM IST
(ツ) We must become the change we want to see.
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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m, ans = 0;
	cin >> n >> m;

	FOR(i,0,n) {
		// i teams of type 1
		int req1 = i, req2 = 2 * i;
		if (req1 > n || req2 > m) continue;
		int rem1 = n - req1;
		int rem2 = m - req2;
		int make1 = rem1 / 2;
		int make2 = rem2 / 1;
		// teams of type 2
		int other = min(make1, make2);
		ans = max(ans, i + other);
	}
	cout << ans;
}
