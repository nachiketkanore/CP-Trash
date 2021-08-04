/*
Author: Nachiket Kanore
Created: Saturday 24 October 2020 08:10:34 PM IST
(ツ) I think somehow we learn who we really are and then live with that decision.
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

int n, a[N], val[N];
std::vector<int> g[N];

void dfs(int curr, int sum) {
	if (!sz(g[curr])) {
		val[curr] = sum;
	}

	int nxt = 0;

	if (sz(g[curr]) > 1) {
		nxt = 0;
	} else if (sz(g[curr]) == 1) {
		nxt = sum;
	}

	for (int to : g[curr]) {
		dfs(to, nxt + a[to]);
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR(i,2,n) {
		int to;
		cin >> to;
		g[to].push_back(i);
	}

	memset(val, -1, sizeof(val));
	FOR(i,1,n) cin >> a[i];

	dfs(1,a[1]);

	FOR(i,1,n) cout << val[i] << " \n"[i == n];

	int ans = 0;

	FOR(i,1,n) if (~val[i]) {
		ans = max(ans, val[i]);
	}

	cout << ans;
}
