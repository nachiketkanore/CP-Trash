/**
 *    Author: Nachiket Kanore
 *    Created: Monday 27 March 2023 09:05:26 PM IST
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

const int _ = 1e6 + 500, INF = 1e12;
// int MX = 1e6 + 100;
int MX = 200;
int N, M, cnt[_], B[_], C[_], keep[_], best[_];
vector<int> divisors[_];

// can be used for Range min/max/gcd range query in O(1)
// only instantiate this class once
// just use different precompute(n) for different testcases
int floorlog[_];

void precompute() {
	for (int i = 0; (1 << i) < MX; i++) {
		for (int j = (1 << i); j < MX && j < (1 << (i + 1)); j++)
			floorlog[j] = i;
	}
}
class sparseTable {
	public:
	int RMQ[22][_];

	void init(int n) {
		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = keep[i];		   // leaf value
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

	precompute();

	cin >> N >> M;
	FOR(i, 1, N) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	FOR(i, 1, M) {
		cin >> B[i];
	}
	FOR(i, 1, M) {
		cin >> C[i];
	}
	F0R(i, _) keep[i] = best[i] = INF;
	FOR(i, 1, M) {
		keep[B[i]] = min(keep[B[i]], C[i]);
	}

	T.init(MX);

	FOR(d, 1, MX) {
		for (int m = d; m <= MX; m += d) {
			divisors[m].push_back(d);
		}
	}

	// // TODO: required?
	// FOR(d, 1, MX) {
	// 	sort(ALL(divisors[d]));
	// }

	int ans = 0;
	for (int x = 1; x <= MX; x++) {
		if (cnt[x] == 0)
			continue;

		int ceil_val = 0;
		for (int one = 1; one <= MX; one += x) {
			ceil_val += 1;
			int two = ceil_val * x;
			if (two > MX)
				two = MX;
			int get = T.query(one, two);
			see(x, one, two, ceil_val, get);
			FOR(A_i, one, two) {
				best[A_i] = min(best[A_i], ceil_val * get);
			}
		}

		// int best = INF;
		// const int len = sz(divisors[x]);
		// F0R(i, len) {
		// 	int curr = divisors[x][i];
		// 	int nxt = (i + 1 < len ? divisors[x][i + 1] - 1 : MX);
		// 	// int nxt = divisors[x][i + 1];
		// 	int ceil_val = (x + curr - 1) / curr;
		// 	int get = T.query(curr, nxt);
		// 	see(T.query(10, 10));
		// 	see(x, curr, nxt, ceil_val, get);
		// 	best = min(best, ceil_val * get);
		// }
		// see(best);
		// ans += cnt[x] * best;
	}
	FOR(x, 1, MX) {
		if (cnt[x]) {
			ans += cnt[x] * best[x];
		}
	}
	cout << ans << '\n';

	return 0;
}
