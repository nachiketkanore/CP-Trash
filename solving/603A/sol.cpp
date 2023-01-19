/*
Author: Nachiket Kanore
Created: Tuesday 17 November 2020 05:31:39 PM IST
(ツ) You can't trust without risk but neither can you live in a cocoon.
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

const int N = 1e5 + 5, inf = 1e18;

int n, a[N];
string s;

int go(int id, int prev, int state) {
	if (id == n)
		return 0;
	int ans = 0;

	if (state == 0) { // can start flipping from here
		int curr = a[id] ^ 1;
		if (curr ^ prev) {
			ans = max(ans, go(id + 1, prev, state));
			ans = max(ans, 1 + go(id + 1, curr, 1));
		}
		ans = max(ans, go(id + 1, prev, state));
	} else if (state == 1) { // already started flipping
		int curr = a[id] ^ 1;
		if (curr ^ prev)
			ans = max(ans, 1 + go(id + 1, curr, 1));
		ans = max(ans, go(id + 1, prev, state));

		ans = max(ans, go(id + 1, prev, 2));
		if (prev ^ a[id])
			ans = max(ans, 1 + go(id + 1, a[id], 2));
	} else { // finished flipping
		if (a[id] ^ prev)
			ans = max(ans, 1 + go(id + 1, a[id], 2));
		ans = max(ans, go(id + 1, prev, 2));
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	FOR(i, 1, n) a[i - 1] = s[i - 1] - '0';
	int ans = max(go(0, 0, 0), go(0, 1, 0));
	cout << ans;
}
