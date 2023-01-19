/*
Created: Saturday 21 November 2020 07:56:00 PM IST
(ツ) Decision is a risk rooted in the courage of being free.
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

int d, k;

int chk(int x, int y) {
	return x * x + y * y <= d * d;
}

int go(int x, int y) {
	int ans = 0;

	if (chk(x + k, y))
		ans |= go(x + k, y) == 0;
	if (chk(x, y + k))
		ans |= go(x, y + k) == 0;

	return ans;
}

void solve(int d, int k) {
	::d = d;
	::k = k;
	cout << (go(0, 0) ? "A\t" : "B\t");
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(d, 1, 20) {
		FOR(k, 1, d) cout << k << '\t';
		cout << "\n";
		FOR(k, 1, d) {
			solve(d, k);
		}
		cout << "\n\n";
	}
}
