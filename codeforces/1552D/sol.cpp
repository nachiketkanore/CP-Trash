/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 14 September 2023 12:02:45 AM IST
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
	int N;
	cin >> N;
	int A[N];
	F0R(i, N) cin >> A[i];

	// iterates over the subset choices
	FOR(mask, 1, (1 << N) - 1) {
		vector<int> ids;
		F0R(id, N) if (mask >> id & 1) ids.push_back(id);

		const int M = ids.size();

		// iterates over the sign choices
		F0R(mask2, 1 << M) {
			int sum = 0;
			F0R(id, M) {
				if (mask2 >> id & 1) {
					sum += A[ids[id]];
				} else {
					sum -= A[ids[id]];
				}
			}
			if (sum == 0) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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
