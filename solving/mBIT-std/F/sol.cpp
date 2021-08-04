/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 02:05:28 PM IST
(ツ) Lose an hour in the morning, and you will spend all day looking for it.
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

using ld = long double;
int n, a[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);

	int sum = 0;
	FOR (i,1,n) sum += a[i];
	int left = 0;
	ld ans = 0;

	FOR (i,1,n-1) {
		left += a[i];
		int right = sum - left;

		ld one = (ld)left/(ld)i;
		ld two = (ld)right/(ld)(n-i);

		ans = max(ans, (ld)abs(one-two));
	}

	printf("%0.10Lf", ans);
}
