/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 11:53:43 PM IST
(ツ) To live a creative life, we must lose our fear of being wrong.
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

const int N = 300 + 5, inf = 1e18;

int n, a[N + 5], dp[N + 5][2], ans;

int getMax(int L, int R, int which) {
	int ret = 0;
	FOR (i, L, R) ret = max(ret, dp[i][which]);
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR (i,1,n) {
		cin >> a[i];
		dp[a[i]][1] = 1;
	}

	FOR (i,1,n) {
		dp[a[i]][1] = 1 + getMax(1, a[i], 0);
		dp[a[i]][0] = 1 + getMax(a[i], N, 1);
		ans = max(ans, max(dp[a[i]][1], dp[a[i]][0])); 
	}

	cout << ans;
}

int sum (int tl, int tr, int v, int ql, int qr) {
	if (tl > tr || ql > qr) 
		return 0;
	if (tl == ql && tr == qr)
		return tree[v];

	int mid = (tl + tr) / 2;

	if (qr <= mid) {		// query lies completely inside left part
		return sum (tl, mid, 2 * v, ql, qr);
	} else if (mid < ql) {	// query lies completely inside right part
		return sum (mid + 1, tr, 2 * v + 1, ql, qr);
	} else {				// query lies in both parts partially
		return sum (tl, mid, 2 * v, ql, mid) + sum (mid + 1, tr, 2 * v + 1, mid + 1, qr);
	}
}