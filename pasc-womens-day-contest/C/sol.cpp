/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 March 2023 11:52:12 PM IST
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

const int _ = 2e5 + 5;
int N, F[3], B[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> F[0] >> F[1] >> F[2];
	FOR(i, 1, N) {
		cin >> B[i];
		B[i] += B[i - 1];
	}

	auto get_index_for_sum_from = [&](int sum, int start_id) {
		int lo = start_id, hi = N;
		int end_id = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int sum_here = B[mid] - B[start_id - 1];
			if (sum_here <= sum) {
				end_id = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (end_id == -1)
			return end_id;
		assert(end_id >= start_id);
		int sum_received = B[end_id] - B[start_id - 1];
		if (sum_received == sum) {
			return end_id;
		}
		return int(-1);
	};

	FOR(i, 1, N) {
		// [i  j], [j+1 k], [k+1 m]
		int j = get_index_for_sum_from(F[0], i);
		if (j == -1)
			continue;
		int k = get_index_for_sum_from(F[1], j + 1);
		if (k == -1)
			continue;
		int m = get_index_for_sum_from(F[2], k + 1);
		if (m == -1)
			continue;
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";

	return 0;
}
