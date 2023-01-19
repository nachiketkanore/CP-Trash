/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 11:15:44 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	std::vector<int> f(26);

	int ans = 0;

	for (char ch : s) {
		f[ch - 'a']++;
		ans = max(ans, f[ch - 'a']);
	}

	cout << ans;
}
