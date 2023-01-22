/*
Created: Saturday 21 November 2020 07:56:00 PM IST
(ツ) To get the full value of joy you must have someone to divide it with.
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

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	while (q--) {
		int l, r;
		cin >> l >> r;
		bool one = false, two = false;
		FOR(i, 1, l - 1) one |= s[i] == s[l];
		FOR(i, r + 1, n) two |= s[i] == s[r];
		if (one || two)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
