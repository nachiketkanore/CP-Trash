/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:04:43 PM IST
(ツ) I know but one freedom and that is the freedom of the mind.
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

void solve() {
	int n;
	cin >> n;
	int a[n + 5] = {};
	int cnt[n + 5] = {};

	FOR (i,1,n) {
		int u;	cin >> u;
		a[i] = u;
		cnt[u]++;
	}
	int which = -1;
	FOR (i,1,n) {
		if (cnt[i] == 1) { which = i; break; }
	}
	if (which == -1) {
		cout << "-1\n";
		return ;
	}
	assert(~which);
	FOR (i,1,n) if (a[i] == which) {
		cout << i << "\n";
		return;
	}
	assert(0);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--) solve();
}
