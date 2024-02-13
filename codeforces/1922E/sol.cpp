/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Tuesday 13 February 2024 05:59:44 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	auto count_increasing_subsequences = [](const vector<int>& A) {
		const int N = sz(A);
		vector<int> dp(N, 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] < A[i])
					dp[i] += dp[j];
			}
		}
		return accumulate(ALL(dp), 1);
	};

	int t;
	cin >> t;
	while (t--) {
		int X;
		cin >> X;
		int msb = 0;
		F0R(bit, 61) if (X >> bit & 1) msb = bit;

		vector<int> ans;
		for (int bit = msb - 1; bit >= 0; bit--) {
			if (X >> bit & 1) {
				// append new max
				ans.push_back(ans.empty() ? 5 : *max_element(ALL(ans)) + 1);
				// append new min
				ans.push_back(*min_element(ALL(ans)) - 1);
			} else {
				// append new max
				ans.push_back(ans.empty() ? 5 : *max_element(ALL(ans)) + 1);
			}
		}

		// assert(count_increasing_subsequences(ans) == X);

		cout << sz(ans) << '\n';
		for (int x : ans) {
			cout << x << ' ';
		}
		cout << '\n';
	}

	return 0;
}
