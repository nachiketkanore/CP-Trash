/*
Author: Nachiket Kanore
Created: Sunday 18 October 2020 02:32:57 PM IST
(ツ) We aim above the mark to hit the mark.
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

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;

		for (int i = 32; i >= 0; i--) {
			if ((a >> i & 1) && (b >> i & 1)) {
				ans |= (1LL << i);
			}
		}

		ans = (ans ^ a) + (ans ^ b);
		cout << ans << '\n';
	}
}
