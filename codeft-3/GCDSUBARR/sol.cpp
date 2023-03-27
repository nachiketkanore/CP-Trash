/**
 *    Author: Nachiket Kanore
 *    Created: Monday 27 March 2023 08:38:29 PM IST
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

// can be used for Range min/max/gcd range query in O(1)
// only instantiate this class once
// just use different precompute(n) for different testcases
const int N = 2e5 + 5;
int n, A[N];
int floorlog[N];
void precompute(int n) {
	for (int i = 0; (1 << i) < N; i++) {
		for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
			floorlog[j] = i;
	}
}
class sparseTable {
	public:
	int RMQ[20][N];

	void init(int n) {
		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = A[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = __gcd(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					   // 2^k <= R-L+1
		return __gcd(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}
} st;

void solve() {
	int L, R, ans = 0;
	cin >> n >> L >> R;
	FOR(i, 1, n) {
		cin >> A[i];
	}
	st.init(n);
	FOR(i, 1, n) {
		int j = i;
		while (j <= n) {
			int curr = st.query(i, j);
			int lo = j, hi = n;
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (st.query(i, mid) == curr) {
					best = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			assert(~best);
			assert(best >= j);
			if (L <= curr && curr <= R) {
				ans += best - j + 1;
			}
			j = best + 1;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	precompute(N);
	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
