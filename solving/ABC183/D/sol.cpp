/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:25:22 PM IST
(ツ) Adversity has the effect of eliciting talents, which in prosperous circumstances would have lain dormant.
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

const int N = 2e5 + 5, M = 2e5 + 10;

int n, w, cnt[M + 5];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w;

	FOR (i,1,n) {
		int L, R, p;
		cin >> L >> R >> p;
		cnt[L] += p, cnt[R] -= p;
	}

	bool ok = true;

	FOR (i,0,M) {
		if (i)
			cnt[i] += cnt[i-1];
		// cerr << cnt[i] << "\n";
		ok &= cnt[i] <= w;
	}
	cout << (ok ? "Yes" : "No");
}
