/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 05:26:06 PM IST
(ツ) Arrogance and rudeness are training wheels on the bicycle of life for weak people who cannot keep their balance without them.
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

int NOD(int n) {
	return (!n ? 0 : 1 + NOD(n / 10));
}

int have, start, k;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> have >> start >> k;

	for (int digs = NOD(start);; digs++) {
	}
}
