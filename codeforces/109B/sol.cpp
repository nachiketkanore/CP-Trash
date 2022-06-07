/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 June 2022 12:24:22 AM IST
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

set<int> vals;

void gen(int curr) {
	if (curr > 1e9)
		return;
	vals.insert(curr);
	gen(curr * 10 + 4);
	gen(curr * 10 + 7);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	gen(4), gen(7);
	const vector<int> A(ALL(vals));

	const int MAX = 1e9;
	int L1, R1, L2, R2, K;
	cin >> L1 >> R1 >> L2 >> R2 >> K;

	auto intersection = [](int l1, int r1, int l2, int r2) {
		if (l1 > r2 || r1 < l2)
			return int(0);
		if (l1 > l2) {
			swap(l1, l2);
			swap(r1, r2);
		}

		assert(l1 <= l2);
		int ret = min(r1, r2) - max(l1, l2) + 1;
		assert(ret > 0);
		return ret;
	};

	assert(intersection(1, 10, 1, 10) == 10);
	assert(intersection(1, 9, 1, 10) == 9);
	assert(intersection(1, 9, 10, 10) == 0);

	int ways = 0;
	int tot = (R1 - L1 + 1) * (R2 - L2 + 1);

	F0R(i, sz(A)) {
		int j = i + K - 1;
		if (j >= sz(A))
			break;
		int L = A[i], R = A[j];
		int left = i - 1 >= 0 ? A[i - 1] + 1 : 1;
		int right = j + 1 < sz(A) ? A[j + 1] - 1 : MAX;

		// person 1 choses from [L1, R1] intersection [left, L]
		// person 2 choses from [L2, R2] intersection [R, right]
		// OR
		// person 2 choses from [L2, R2] intersection [left, L]
		// person 1 choses from [L1, R1] intersection [R, right]

		bool both = intersection(L1, R1, A[i], A[i]) && intersection(L2, R2, A[i], A[i]);

		int c1 = intersection(L1, R1, left, L);
		int c2 = intersection(L2, R2, R, right);

		/* if (c1 * c2 > 0) {
			see("checking", L, R);
			see(left, L, R, right);
			see(c1, c2);
		} */
		ways += c1 * c2;

		c1 = intersection(L1, R1, R, right);
		c2 = intersection(L2, R2, left, L);

		ways += c1 * c2;

		if (K == 1 && both)
			--ways;
	}

	// see(ways, tot);
	cout << fixed << setprecision(12) << 1. * ways / tot << '\n';

	return 0;
}
