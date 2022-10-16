/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 08:08:19 PM IST
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

void solve() {
	int N, Q;
	cin >> N >> Q;
	int odd_cnt = 0, even_cnt = 0;
	int sum = 0;
	F0R(i, N) {
		int u;
		cin >> u;
		if (u & 1)
			odd_cnt++;
		else
			even_cnt++;
		sum += u;
	}
	while (Q--) {
		int type, x;
		cin >> type >> x;
		if (type == 0) {
			sum += x * even_cnt;
			// add to even
			if (x % 2 == 0) {
				// same even_cnt
			} else {
				odd_cnt += even_cnt;
				even_cnt = 0;
			}
		} else {
			// add to odd
			sum += x * odd_cnt;
			if (x % 2 == 0) {
				// same odd_cnt
			} else {
				even_cnt += odd_cnt;
				odd_cnt = 0;
			}
		}
		cout << sum << '\n';
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
