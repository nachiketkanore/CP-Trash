/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 07 March 2023 01:43:44 PM IST
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

const int _ = 2e5 + 5, INF = 1e9;
int N, A[_], dp[_], dp_pref_max[_], ans;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	/* // O(N*N*N)
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = i; j >= 1; j--) {
			if (A[i] - A[j - 1] >= 0) {
				int best_pref = 0;
				FOR(k, 1, j - 1) best_pref = max(best_pref, dp[k]);
				dp[i] = max(dp[i], (i - j + 1) + best_pref);
			}
		}
		ans = max(ans, dp[i]);
	} */

	// O(N*N)
	/* FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = i; j >= 1; j--) {
			if (A[i] - A[j - 1] >= 0) {
				int best_pref = dp_pref_max[j - 1];
				dp[i] = max(dp[i], (i - j + 1) + best_pref);
			}
		}
		dp_pref_max[i] = max(dp_pref_max[i], dp[i]);
		ans = max(ans, dp[i]);
	} */

	// Better solution?
	/*
		Codeforces 1788 E- Sum Over Zero
		- Find maximum sum of lengths of disjoint
		subarrays with sum >= 0
		- DP approach: O(N*N)
		 - Let dp[i] = best answer upto index i
		 - dp[i] = max(max(dp[1..j-1]) + (i-j+1))
					if A[j...i] sum is >= 0
		 - max(dp[1..j-1]) is prefix max of dp array
		 - it can be precomputed on the go

		dp[i] = max(pref_dp[j-1] + (i-j+1))
				for all j <= i and sum(A[j..i]) >= 0
		=> sum(A[j..i]) >= 0
		=> pref[i] - pref[j-1] >= 0
		=> pref[j-1] <= pref[i]
		=> so, for i, all prefixes j with pref[j] <= pref[i]
		need to be considered
		=> for all those j, we need 2 things:
			j and pref_dp[j]
		=> dp[i] = max(pref_dp[j-1] + i - (j-1))
		=> dp[i] = i + max(pref_dp[j-1] - (j-1))
				 = i + max(pref_dp[idx] - idx)
				   where pref[idx] <= pref[i]
		=> after computing dp[i],
			we compute pref_dp[i]
			let key = pref[i]
			let value = pref_dp[i] - i
			store key -> value in some data structure
			which can retrieve range maximums quickly
	*/
	// TODO
	vector<pair<int, int>> my_data_structure;
	my_data_structure.push_back({ 0, 0 });
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
		int best = -INF;
		bool found = false;
		for (auto [key, value] : my_data_structure) {
			if (key <= A[i]) {
				best = max(best, value);
				found = true;
			}
		}
		if (found) {
			dp[i] = i + best;
		}
		dp_pref_max[i] = max(dp_pref_max[i - 1], dp[i]);
		my_data_structure.push_back(make_pair(A[i], dp_pref_max[i] - i));
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}
