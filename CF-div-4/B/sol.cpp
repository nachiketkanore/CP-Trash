/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:06:48 PM IST
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
	sort(A, A + N);
	for (int i = 1; i < N; i++) {
		if (A[i - 1] == A[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
