/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 18 January 2022 03:34:54 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int tests;
	for (cin >> tests; tests > 0; tests--) {
		int N; cin >> N;
		int ans = 1LL << 31;
		for (int i = 0, u; i < N; i++) {
			cin >> u;
			ans = min(ans, u);
		}
		cout << ans << '\n';
	}
	return 0;
}
