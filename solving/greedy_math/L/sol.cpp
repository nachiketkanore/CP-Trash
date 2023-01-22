/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 08:01:32 PM IST
(ツ) I always wanted to be somebody, but I should have been more specific.
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

	array<int, 3> ans = { inf, -1, -1 };

	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) {
			int one = i, two = n / i;
			if (__gcd(one, two) == 1) {
				ans = min(ans, { max(one, two), one, two });
			}
		}

	cout << ans[1] << " " << ans[2] << "\n";
}
