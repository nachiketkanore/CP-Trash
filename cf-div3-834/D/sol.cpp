/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 08:20:40 PM IST
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

int trail(int u) {
	int ret;
	while (u % 10 == 0) {
		ret++;
		u /= 10;
	}
	return ret;
}

void solve() {
	int n, m;
	cin >> n >> m;

	int curr = trail(n);
	int ans = -1;
	int a = 0, b = 0;

	{
		int N = n;
		while (N % 2 == 0) {
			N /= 2;
			a++;
		}
		while (N % 5 == 0) {
			N /= 5;
			b++;
		}
	}

	int lo = 0, hi = 20;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int two_req = max(mid - a, int(0));
		int five_req = max(mid - b, int(0));
		int k = 1;
		bool bad = false;
		F0R(j, two_req) {
			k *= 2;
			if (k > m) {
				bad = true;
				break;
			}
		}
		F0R(j, five_req) {
			k *= 5;
			if (k > m) {
				bad = true;
				break;
			}
		}

		if (!bad) {
			int mul = m / k;
			k *= mul;
			int t = trail(n * k);
			if (t > curr) {
				curr = t;
				ans = n * k;
			} else if (t == curr) {
				ans = max(ans, n * k);
			}

			lo = mid + 1;
		} else {
			hi = mid - 1;
		}

		// if (k <= m && !bad) {
		// 	int mul = m / k;
		// 	k *= mul;
		// 	if (trail(n * k) > curr) {
		// 		curr = trail(n * k);
		// 		ans = n * k;
		// 	}
		// }
	}
	if (ans == -1)
		ans = n * m;
	cout << ans << '\n';
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
