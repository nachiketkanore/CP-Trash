/*
Author: Nachiket Kanore
Created: Sunday 22 November 2020 05:25:16 PM IST
(ツ) You need chaos in your soul to give birth to a dancing star.
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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a * d - b * c);
}
