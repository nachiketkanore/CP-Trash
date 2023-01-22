/*
Author: Nachiket Kanore
Created: Tuesday 10 November 2020 12:24:16 PM IST
(ツ) The truth is always exciting. Speak it, then. Life is dull without it.
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

int getPowerIn(int x, int p) {
	int cnt = 0;
	while (x % p == 0)
		x /= p, ++cnt;
	assert(cnt > 0);
	return cnt;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		if (a < b)
			cout << a << "\n";
		else {
			if (a % b) {
				cout << a << "\n";
				continue;
			}

			// a = k.b
			int bb = b;
			vector<int> B;
			for (int d = 2; d * d <= b; d++)
				if (b % d == 0) {
					B.push_back(d);
					while (b % d == 0)
						b /= d;
				}
			if (b > 1)
				B.push_back(b);

			int ans = 0;

			for (int p : B) {
				int powInA = getPowerIn(a, p);
				__int128 rem = 1;
				FOR(i, 1, powInA + 1) {
					int getAns = a / rem;
					if (getAns % bb)
						ans = max(ans, getAns);
					rem *= p;
				}
			}
			cout << ans << "\n";
		}
	}
}
