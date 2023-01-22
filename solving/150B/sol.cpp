/*
Author: Nachiket Kanore
Created: Tuesday 17 November 2020 05:06:16 PM IST
(ツ) The odds of hitting your target go up dramatically when you aim at it.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int mod = 1e9 + 7;

int power(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	if (k == 1 || k > n)
		cout << power(m, n);
	else if (k == n)
		cout << power(m, (n + 1) >> 1);
	else {
		if (k & 1)
			cout << power(m, 2);
		else
			cout << m;
	}
}
