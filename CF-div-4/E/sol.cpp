/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:16:09 PM IST
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
	vector<int> A(N + 1), pref(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
		pref[i] = pref[i - 1] + A[i];
		A[i] = max(A[i], A[i - 1]);
	}
	while (Q--) {
		int k;
		cin >> k;
		int lo = 1, hi = N;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (A[mid] <= k) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		cout << pref[ans] << ' ';
	}
	cout << '\n';
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
