/**
 *    Author: Nachiket Kanore
 *    Created: Monday 10 October 2022 09:15:29 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast32_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MX = 2e5 + 5;
int N, A[MX];

// can be used for Range min/max/gcd range query in O(1)
// only instantiate this class once
// just use different precompute(n) for different testcases
class sparseTable {
	public:
	int RMQ[20][MX];
	int floorlog[MX];

	void precompute(int n) {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}

		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = A[i];			   // leaf value
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

void solve() {
	long long ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] = i - A[i] + 1;
	}
	T.precompute(N);
	FOR(i, 1, N) {
		int lo = i, hi = N;
		int j = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (T.query(i, mid) >= i) {
				hi = mid - 1;
			} else {
				j = mid;
				lo = mid + 1;
			}
		}
		assert(~j);
		see(i, j);
		ans += j - i + 1;
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
