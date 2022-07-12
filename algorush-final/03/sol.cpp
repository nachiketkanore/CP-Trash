/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 12:01:00 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast16_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& x : A) {
		cin >> x;
	}
	if (A.back() ^ 100) {
		A.push_back(100);
	}

	reverse(ALL(A));
	if (A.back() != 0) {
		A.push_back(0);
	}
	reverse(ALL(A));
	// assert(is_sorted(ALL(A)));

	vector<int> answers;

	FOR(d, 1, 100) {
		bool ok = true;
		for (int i = 1; i < sz(A) - 1; i++) {
			ok &= (A[i] - A[i - 1]) % d == 0;
			if (!ok)
				break;
		}
		if (ok) {
			answers.push_back(d);
		}
	}

	for (int x : answers) {
		cout << x << ' ';
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
