/** - saw the editorial
 *    Author: Nachiket Kanore
 *    Created: Wednesday 31 January 2024 07:42:56 PM IST
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

void solve() {
	int N, Q;
	cin >> N >> Q;
	assert(Q == 1);
	vector<int> A(N + 1), psum(N + 1), pxor(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
		psum[i] = A[i] + psum[i - 1];
		pxor[i] = A[i] ^ pxor[i - 1];
	}
	while (Q--) {
		int L, R;
		cin >> L >> R;
		assert(L == 1 && R == N);
	}

	const int INF = 1e18;
	int best_answer = -INF;
	int ans_left = -1, ans_right = -1;

	auto compute_function = [&](int L, int R) { return (psum[R] - psum[L - 1]) - (pxor[R] ^ pxor[L - 1]); };

	FOR(L, 1, N) {
		int answer_here = compute_function(L, N);
		int lo = L, hi = N;
		int best_r = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (compute_function(L, mid) == answer_here) {
				best_r = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		assert(~best_r);
		if (answer_here > best_answer) {
			best_answer = answer_here;
			ans_left = L, ans_right = best_r;
		} else if (answer_here == best_answer) {
			if ((ans_right == -1) || (ans_right - ans_left > best_r - L)) {
				ans_left = L, ans_right = best_r;
			}
		}
	}

	assert(~ans_left && ~ans_right);
	cout << ans_left << ' ' << ans_right << '\n';
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
