/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 09:18:48 PM IST
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
	vector<vector<int>> A(N);
	F0R(i, N) {
		int u;
		cin >> u;
		A[i].push_back(u);
	}
	int ans = 0;
	while (sz(A) != 1) {
		vector<vector<int>> nA;
		for (int i = 0; i < sz(A); i += 2) {
			vector<int> comb = A[i];
			for (int x : A[i + 1]) {
				comb.push_back(x);
			}
			const auto& same = comb;
			vector<int> rev = A[i + 1];
			for (int x : A[i]) {
				rev.push_back(x);
			}
			if (is_sorted(ALL(same))) {
				nA.push_back(same);
			} else if (is_sorted(ALL(rev))) {
				nA.push_back(rev);
				++ans;
			} else {
				cout << "-1\n";
				return;
			}
		}
		// see(nA);
		assert(2 * sz(nA) == sz(A));
		A = nA;
	}
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
