/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:54:55 PM IST
(ツ) Six essential qualities that are the key to success: Sincerity, personal integrity, humility, courtesy, wisdom, charity.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;

	string s = "abc";
	FOR(i, 1, n) cout << s[(i - 1) % 3];
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
