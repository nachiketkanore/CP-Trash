/** - wrong approach, made some mistake with the equation
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

	auto comparison = [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first)
			return a.second > b.second;
		return a.first < b.first;
	};

	set<pair<int, int>, decltype(comparison)> pref_vals(comparison);
	pref_vals.insert({ 0, 0 });

	const int INF = 1e18;
	int best_answer = -INF;
	int ans_left = -1, ans_right = -1;

	FOR(R, 1, N) {
		auto [min_pref_val, l] = *pref_vals.begin();
		// see(R);
		// for (auto [val, l] : pref_vals) {
		// 	see(val, l);
		// }
		int answer_here = (psum[R] - pxor[R]) - (min_pref_val);

		if (answer_here > best_answer) {
			best_answer = answer_here;
			ans_left = l, ans_right = R;
		} else if (answer_here == best_answer) {
			if ((ans_right == -1) || (ans_right - ans_left >= R - l)) {
				ans_left = l, ans_right = R;
			}
		}
		pref_vals.insert({ (psum[R] - pxor[R]), R });
	}

	see(best_answer);
	cout << ans_left + 1 << ' ' << ans_right << '\n';
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
