/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 25 May 2022 11:52:27 AM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N;
	cin >> N;

	int A[N], B[N];
	F0R(i, N) cin >> A[i];
	F0R(i, N) cin >> B[i];

	vector<pair<int, int>> swaps;

	F0R(i, N) {
		F0R(j, i) {
			if (A[j] >= A[i] && B[j] >= B[i]) {
				swap(A[i], A[j]);
				swap(B[i], B[j]);
				swaps.push_back(make_pair(i + 1, j + 1));
			}
		}
	}

	if (is_sorted(A, A + N) && is_sorted(B, B + N)) {
		assert(sz(swaps) <= 10000);
		cout << sz(swaps) << '\n';
		for (auto [i, j] : swaps) {
			cout << i << ' ' << j << '\n';
		}
	} else {
		cout << "-1\n";
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
