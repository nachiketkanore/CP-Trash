/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 May 2022 07:54:19 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	x -= a;
	y -= b;
	int req = x <= 0 ? 0 : x;
	req += y <= 0 ? 0 : y;
	if (req <= c) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
