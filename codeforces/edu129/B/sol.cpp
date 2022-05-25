/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 25 May 2022 11:50:09 AM IST
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
	int A[N];
	F0R(i, N) cin >> A[i];

	int top = 0;

	int M;
	cin >> M;
	while (M--) {
		int move;
		cin >> move;

		top = (top + move) % N;
	}

	cout << A[top] << '\n';
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
