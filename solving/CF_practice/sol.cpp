/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 11:24:52 AM IST
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, p[N], dp[N], pos[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> p[i];
		pos[p[i]] = i;
	}

	FOR(i, 1, n) dp[i] = 1;

	FOR(i, 2, n) {
		if (pos[i - 1] < pos[i]) {
			dp[i] = max(dp[i], 1 + dp[i - 1]);
		}
	}
	int mx = *max_element(dp + 1, dp + n + 1);
	cout << (n - mx) << '\n';
}
