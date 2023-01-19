/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 September 2022 06:29:40 PM IST
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

const int MX = 303, N = 150005, INF = 1e18;
int n, m, d, a[MX], b[MX], t[MX];
vector<int> dp;

struct sparse_table {
	public:
	int RMQ[20][N];
	int floorlog[N];

	void build(int n) {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}

		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = dp[i];			   // leaf value
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
} ST;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
	   dp[i][pos] = max score when we are at position `pos` for i-th firework
	   next, we can go for i+1-th firework
	   time available T = t[i + 1] - t[i]
	   what positions can I move to: pos - d, pos - 2d, pos - 3d, ..., pos - Td
									 pos + d, pos + 2d, pos + 3d, ..., pos + Td
								   : [pos - Td, pos + Td]
		next_pos belongs to [pos - Td, pos + Td]
		So, dp[i][pos] = dp[i - 1][prev_pos] + (b[i] - |a[i] - prev_pos|)
					   = max of:
					   = dp[i - 1][pos - d] + (b[i] - |a[i] - pos|)
					   = dp[i - 1][pos - 2d] + (b[i] - |a[i] - pos|)
					   = dp[i - 1][pos - 3d] + (b[i] - |a[i] - pos|)
					   = dp[i - 1][pos - Td] + (b[i] - |a[i] - pos|) ..
					   = ...
					   = dp[i - 1][pos + d] + (b[i] - |a[i] - pos|)
					   = dp[i - 1][pos + 2d] + (b[i] - |a[i] - pos|)
					   = dp[i - 1][pos + 3d] + (b[i] - |a[i] - pos|) ..
					   = dp[i - 1][pos + Td] + (b[i] - |a[i] - pos|)
		where T = t[i] - t[i - 1]
	*/

	// not optimized
	cin >> n >> m >> d;
	FOR(i, 1, m) {
		cin >> a[i] >> b[i] >> t[i];
	}
	dp = vector<int>(n + 1);
	FOR(i, 1, m) {
		ST.build(n);
		vector<int> ndp(n + 1, -INF);
		FOR(pos, 1, n) {
			int T = t[i] - t[i - 1];
			int L = max(int(1), pos - T * d);
			int R = min(n, pos + T * d);
			/* FOR (npos, max(int(1), pos - T*d), min(n, pos + T*d)) {
				ndp[npos] = max(ndp[npos], b[i] - abs(a[i] - npos) + dp[pos]);
			} */
			int best_dp = ST.query(L, R);
			ndp[pos] = max(ndp[pos], b[i] - abs(a[i] - pos) + best_dp);
			// FOR (ppos,L,R) {
			// 	ndp[pos] = max(ndp[pos], b[i] - abs(a[i] - pos) + dp[ppos]);
			// }
		}
		swap(dp, ndp);
	}
	cout << *max_element(ALL(dp));
	return 0;
}
