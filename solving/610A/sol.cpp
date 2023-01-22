/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 11:04:40 AM IST
(ツ) Three things cannot be long hidden: the sun, the moon, and the truth.
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

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n & 1) {
		cout << "0\n";
	} else {
		n >>= 1;
		int ans = n >> 1;
		if (n % 2 == 0)
			--ans;
		cout << ans << "\n";
	}
}
