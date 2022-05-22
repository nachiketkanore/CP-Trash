/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 22 May 2022 04:25:10 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, L;
	cin >> N >> L;
	vector<pair<int, int>> A(N);
	F0R(i, N) {
		cin >> A[i].first;
		int dir;
		cin >> dir;
		A[i].second = (dir == 0 ? -1 : +1);
	}

	vector<int> ans;

	while (!A.empty()) {
		sort(ALL(A));
		const int M = A.size();

		for (int i = 0; i < M; i++) {
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
