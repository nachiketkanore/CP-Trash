/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 November 2022 08:20:38 PM IST
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
	string S = "#";
	F0R(i, N) S += "BAN";

	vector<pair<int, int>> ans;

	for (int i = 3 * N; i >= 1; i--) {
		if (S[i] == 'A') {
			FOR(j, 1, i - 1) {
				if (S[j] == 'B') {
					swap(S[i], S[j]);
					ans.push_back({ i, j });
					break;
				}
			}
		}
	}
	cout << sz(ans) << '\n';
	for (auto [i, j] : ans) {
		cout << i << ' ' << j << '\n';
	}
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
