/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 06 November 2022 08:08:51 PM IST
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
	vector<int> A(N + 1);
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			FOR(k, j + 1, N) {
				if (A[i] <= A[k] && A[j] > A[k]) {
					swap(A[j], A[k]);
				}
			}
		}
	}
	// see(A);
	bool ok = true;
	FOR(i, 2, N) ok &= A[i - 1] < A[i];
	cout << (ok ? "Yes" : "No") << '\n';
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
