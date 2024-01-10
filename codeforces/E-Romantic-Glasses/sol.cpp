/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 10 January 2024 03:51:21 PM IST
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
	vector<int> A(N), B(N);
	F0R(i, N) {
		int val;
		cin >> val;
		if (i & 1) {
			A[i] = val;
			B[i] = -val;
		} else {
			A[i] = -val;
			B[i] = val;
		}
	}
	map<int, bool> psums;
	psums[0] = true;
	int pref_sum = 0;
	F0R(i, N) {
		pref_sum += A[i];
		if (A[i] < 0) {
			if (psums.count(pref_sum)) {
				cout << "YES\n";
				return;
			}
		}
		psums[pref_sum] = true;
	}
	psums.clear();
	psums[0] = true;
	pref_sum = 0;
	F0R(i, N) {
		pref_sum += B[i];
		if (B[i] < 0) {
			if (psums.count(pref_sum)) {
				cout << "YES\n";
				return;
			}
		}
		psums[pref_sum] = true;
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
