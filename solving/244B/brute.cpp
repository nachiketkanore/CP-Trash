/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 07:56:08 PM IST
(ツ) The way we communicate with others and with ourselves ultimately determines the quality of our lives.
*/
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, x, y;
set<int> vals;

void dfs(int val) {
	if (val > n)
		return;
	if (val == 0 && x == 0)
		return;
	if (val == 0 && y == 0)
		return;
	vals.insert(val);
	dfs(val * 10 + x);
	dfs(val * 10 + y);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 0, 9) FOR(j, i, 9) {
		x = i;
		y = j;
		dfs(0);
	}
	cout << sz(vals) - 1;
}
