/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 June 2024 10:27:10 PM IST
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

const int _ = 3e5 + 5;
const int MAX_N = 3e5 + 5;
int N, M, P[_], index_of[_], edge_right[_];
pair<int, int> F[_];

class sparseTable {

	public:
	int RMQ[20][MAX_N];
	int floorlog[MAX_N];

	sparseTable() {
		for (int i = 0; (1 << i) < MAX_N; i++) {
			for (int j = (1 << i); j < MAX_N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}
	}

	void precompute(int n, int* arr) {
		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = arr[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = min(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					 // 2^k <= R-L+1
		return min(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}
} T;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> P[i];
		index_of[P[i]] = i;
		edge_right[i] = N + 1;
	}
	FOR(i, 1, M) cin >> F[i].first >> F[i].second;
	FOR(i, 1, M) {
		auto [a, b] = F[i];
		if (index_of[a] > index_of[b]) {
			swap(a, b);
		}
		edge_right[index_of[a]] = min(edge_right[index_of[a]], index_of[b]);
	}

	T.precompute(N, edge_right);

	int answer = 0;
	FOR(L, 1, N) {
		int best_R = 0;

		/* 		brute approach		*/

		// int min_right = N + 1;
		// FOR(R, L, N) {
		// 	min_right = min(min_right, edge_right[R]);
		// 	if (min_right <= R) {
		// 		break;
		// 	} else {
		// 		best_R = R;
		// 	}
		// }

		int lo = L, hi = N;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (T.query(L, mid) <= mid) {
				hi = mid - 1;
			} else {
				best_R = mid;
				lo = mid + 1;
			}
		}

		if (best_R > 0)
			answer += best_R - L + 1;
	}

	cout << answer << '\n';

	return 0;
}
