/*
Author: Nachiket Kanore
Created: Wednesday 11 November 2020 02:53:08 PM IST
(ツ) Everyone is a genius at least once a year. A real genius has his original ideas closer together.
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

int n, a[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,1,n) cin >> a[i];

	int right = 0, left = 0;
	FOR (i,1,n) {
		right += a[i] <= 0;
	}

	int ans = inf;
	FOR (i,1,n-1) {
		left += a[i] >= 0;
		right -= a[i] <= 0;
		ans = min(ans, left + right);
	}
	cout << ans;
}
