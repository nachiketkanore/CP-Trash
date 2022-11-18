/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 09:26:28 PM IST
 **/
#include "bits/stdc++.h"
#include <algorithm>
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
	int N, H;
	cin >> N >> H;
	int A[N];
	F0R(i, N) cin >> A[i];
	sort(A, A + N);

	vector<int> order = { 2, 2, 3 };

	int ans = 0;
	do {
		int best = 0, j = 0, h = H;
		F0R(i, N) {
			while (j < 3 && A[i] >= h) {
				h *= order[j];
				j++;
			}
			if (A[i] < h) {
				// see(order, j, h);
				best++;
				h += A[i] / 2;
			}
		}
		ans = max(ans, best);
	} while (next_permutation(ALL(order)));

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
