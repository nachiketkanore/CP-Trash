/**
 *    Author: Nachiket Kanore
 *    Created: Monday 14 March 2022 07:05:51 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int L, R;

int f(int x, int a) {
	if (a <= 0 || !(L <= x && x <= R))
		return 0;
	return (x / a) + (x % a);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int a;
		cin >> L >> R >> a;
		int ans = max(f(L, a), f(R, a));
		for (int d = 1; d * d <= a; d++) {
			if (a % d == 0) {
				int one = d, two = a / d;
				ans = max(ans, f(one, a));
				ans = max(ans, f(one - 1, a));
				ans = max(ans, f(one + 1, a));
				ans = max(ans, f(two, a));
				ans = max(ans, f(two - 1, a));
				ans = max(ans, f(two + 1, a));
			} else {
				ans = max(ans, f(d - 1, a));
				ans = max(ans, f(d, a));
				ans = max(ans, f(d + 1, a));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
