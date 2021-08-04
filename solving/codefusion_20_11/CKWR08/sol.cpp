/*
Author: Nachiket Kanore
Created: Tuesday 01 December 2020 11:40:50 AM IST
(ツ) He who lives in harmony with himself lives in harmony with the world.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n, mx = -inf, mn = inf, k;
	cin >> n >> k;
	FOR (i,1,n) {
		int u;	cin >> u;
		mx = max(mx, u);
		mn = min(mn, u);
	}
	cout << (mx-mn+2*k) << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T; while (T--) solve();
}
