/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 June 2022 12:38:44 AM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// not optimal

	int N, Q;
	cin >> N >> Q;

	set<int> pts;
	F0R(i, N) {
		int u;
		cin >> u;
		pts.insert(u);
	}

	auto solve = [&]() {
		vector<int> P(ALL(pts));
		sort(ALL(P));
		// see(P);

		if (P.empty())
			return int(0);

		const int M = sz(P);
		int L = P[0], R = P[M - 1];
		int mid = (L + R) / 2;
		mid = lower_bound(ALL(P), mid) - P.begin();

		int ans = 1e18;
		FOR(m, mid - 2, mid + 2) {
			if (m >= 0 && m < M) {
				int cost = abs(P[m] - P[0]) + abs(P[M - 1] - P[m]);
				ans = min(ans, cost);
			}
		}

		mid = (L + R) / 3;

		int M1 = L + mid;
		M1 = lower_bound(ALL(P), M1) - P.begin();
		int M2 = R - mid;
		M2 = lower_bound(ALL(P), M2) - P.begin();

		FOR(m1, M1 - 2, M1 + 2) {
			FOR(m2, M2 - 2, M2 + 2) {
				if (m1 >= 0 && m1 < M && m2 >= 0 && m2 < M) {
					int l = m1, r = m2;
					if (l > r)
						swap(l, r);

					int cost = abs(P[0] - P[l]);
					cost += abs(P[M - 1] - P[r]);

					int best = (l == r ? 0 : 1e18);
					for (int i = l; i < r; i++) {
						best = min(best, abs(P[i] - P[l]) + abs(P[i + 1] - P[r]));
					}

					cost += best;
					ans = min(ans, cost);
				}
			}
		}

		return ans;
	};

	cout << solve() << '\n';

	while (Q--) {
		int type, x;
		cin >> type >> x;

		if (type == 0) {
			assert(pts.count(x));
			pts.erase(x);
		} else {
			pts.insert(x);
		}
		cout << solve() << '\n';
	}

	return 0;
}
