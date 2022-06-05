/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 June 2022 11:10:12 PM IST
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

	int N, M;
	cin >> N >> M;

	vector<int> A(N + 1);
	FOR(i, 1, N) cin >> A[i];

	int ans = *max_element(A.begin() + 1, A.end()) - *min_element(A.begin() + 1, A.end());
	vector<int> queries;

	vector<array<int, 2>> Q(M);
	for (auto& [L, R] : Q)
		cin >> L >> R;

	FOR(i, 1, N) {
		vector<int> B = A;
		vector<int> taken;
		F0R(j, M) {
			auto [L, R] = Q[j];
			if (R < i || L > i) {
				FOR(k, L, R) {
					--B[k];
				}
				taken.push_back(j + 1);
			}
		}

		int get = *max_element(B.begin() + 1, B.end()) - *min_element(B.begin() + 1, B.end());
		if (get > ans) {
			ans = get;
			queries = taken;
		}
	}

	cout << ans << '\n';
	// cout << sz(queries) << '\n';
	// for (int q : queries)
	// 	cout << q << ' ';

	return 0;
}
/*
   current time complexity = O(N * N * M)
   can reduce to O(N * M)
*/
