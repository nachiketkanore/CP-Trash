/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 May 2022 12:22:26 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> pos(N + 1);

	int A[N];
	F0R(i, N) {
		cin >> A[i];
		pos[A[i]].push_back(i + 1);
	}

	int Q;
	cin >> Q;

	while (Q--) {
		int L, R, X;
		cin >> L >> R >> X;

		cout << (upper_bound(ALL(pos[X]), R) - pos[X].begin()) - (lower_bound(ALL(pos[X]), L) - pos[X].begin()) << '\n';
	}

	return 0;
}
