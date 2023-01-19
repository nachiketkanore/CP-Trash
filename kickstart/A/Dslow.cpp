/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 09:27:28 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int prod(int u) {
	if (u < 10)
		return u;
	return (u % 10) * prod(u / 10);
}

int sum(int u) {
	if (u < 10)
		return u;
	return (u % 10) + sum(u / 10);
}

void solve() {
	int A, B;
	cin >> A >> B;
	int ans = 0;
	for (int i = A; i <= B; i++) {
		if (prod(i) % sum(i) == 0) {
			++ans;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
