/**
 *    Author: Nachiket Kanore
 *    Created: Monday 12 February 2024 06:31:09 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

// can be used for Range min/max/gcd range query in O(1)
// only instantiate this class once
// just use different precompute(n) for different testcases
const int N = 2e5 + 5;
class sparseTable {
	public:
	int RMQ[20][N];
	int floorlog[N];

	sparseTable() {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}
	}

	void init(int n, int* arr) {
		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = arr[i - 1];		   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					 // 2^k <= R-L+1
		return max(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}
} table;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		bool ok = true;
		int N, M;
		cin >> N;
		int A[N];
		F0R(i, N) cin >> A[i];
		int B[N];
		F0R(i, N) {
			cin >> B[i];
			if (B[i] > A[i])
				ok = false;
		}

		table.init(N, B);
		cin >> M;

		map<int, int> X;
		while (M--) {
			int x;
			cin >> x;
			X[x]++;
		}

		auto get_index = [&](int from, int val) {
			assert(from < N);
			from++;
			int lo = from, hi = N;
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (table.query(from, mid) <= val) {
					best = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			assert(~best);
			return best - 1;
		};

		vector<int> remove_updates[N];
		multiset<int> take_min_with;

		F0R(i, N) {
			for (int remove_value : remove_updates[i]) {
				assert(take_min_with.count(remove_value));
				take_min_with.erase(take_min_with.find(remove_value));
			}
			if (sz(take_min_with)) {
				A[i] = min(A[i], *take_min_with.begin());
			}
			if (A[i] == B[i])
				continue;
			int x = B[i];
			if (X[x] > 0) {
				X[x]--;
				take_min_with.insert(x);
				int upto = get_index(i, B[i]);
				if (upto + 1 < N) {
					remove_updates[upto + 1].push_back(x);
				}
				// FOR(j, i, upto) {
				// 	if (B[j] <= B[i]) {
				// 		A[j] = min(A[j], x);
				// 	} else {
				// 		break;
				// 	}
				// }
				// for (int j = i; j < N; j++) {
				// 	if (B[j] <= B[i]) {
				// 		A[j] = min(A[j], x);
				// 	} else {
				// 		break;
				// 	}
				// }
			} else {
				ok = false;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}
