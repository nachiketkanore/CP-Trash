/**
 *    Author: Nachiket Kanore
 *    Created: Monday 17 October 2022 02:15:43 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

vector<int> get_divisors(int n) {
	vector<int> ret;
	for (int d = 1; d * d <= n; d++) {
		if (n % d == 0) {
			ret.push_back(d);
			if (d != n / d) {
				ret.push_back(n / d);
			}
		}
	}
	return ret;
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<int> da = get_divisors(a);
	vector<int> db = get_divisors(b);

	for (int d1 : da) {
		for (int d2 : db) {
			int x = d1 * d2;
			int k1 = a / x + 1;
			x *= k1;
			int y = (a * b) / (d1 * d2);
			int k2 = b / y + 1;
			y *= k2;
			if (x <= c && y <= d) {
				cout << x << ' ' << y << '\n';
				return;
			}
		}
	}
	cout << "-1 -1\n";
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
