/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 13 February 2024 03:06:15 PM IST
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

const int MAX_N = 2e5 + 5;
int A[MAX_N], same[MAX_N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, q, l, r;
	cin >> t;
	while (t--) {
		cin >> n;
		FOR(i, 1, n) cin >> A[i];
		same[n] = 1;
		for (int i = n - 1; i >= 1; i--) {
			if (A[i] == A[i + 1]) {
				same[i] = 1 + same[i + 1];
			} else {
				same[i] = 1;
			}
		}
		cin >> q;
		while (q--) {
			cin >> l >> r;
			int count = same[l];
			if (l + count > r) {
				cout << "-1 -1\n";
			} else {
				cout << l << ' ' << l + count << '\n';
			}
		}
	}

	return 0;
}
