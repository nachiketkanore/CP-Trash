/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 01:59:42 PM IST
(ツ) Obstacles are those things you see when you take your eyes off the goal.
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

const int N = 1e5 + 5, inf = 1e18;

int n, k, a[N], b[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;

	FOR (i,1,n) cin >> a[i];
	sort (a + 1, a + n + 1);
	
	int ans = 0;

	FOR (i,1,n) {
		b[i] = a[i];
		ans = max(ans, b[i]);
		b[i] += b[i-1];
	}

	for (int i = 1; i <= n; ) {
		int j = i + 1;
		while (j <= n && a[j] - a[j-1] <= k) ++j;
		--j;
		int get = b[j] - b[i-1];
		ans = max(ans, get);
		i = j + 1;
	}

	cout << ans << "\n";
}
