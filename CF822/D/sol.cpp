/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 September 2022 06:46:18 PM IST
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

bool solve() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
	}
	int S = A[K];
	int cL = K, cR = K;
	while (true) {
		assert(S >= 0);
		if (cL == 1 || cR == N)
			return true;
		int L = cL;
		int left = S;
		int best_left = S;
		int best_left_pos = L;
		while (L - 1 >= 1 && left + A[L - 1] >= 0) {
			left += A[L - 1];
			L -= 1;
			if (left > best_left) {
				best_left = left;
				best_left_pos = L;
			}
		}
		int R = cR;
		int right = S;
		int best_right = S;
		int best_right_pos = R;
		while (R + 1 <= N && right + A[R + 1] >= 0) {
			right += A[R + 1];
			R += 1;
			if (right > best_right) {
				best_right = right;
				best_right_pos = R;
			}
		}
		if (L == 1 || R == N)
			return true;
		if (L == cL && R == cR)
			return false;

		if (best_left > S && best_right > S) {
			// take the maximum ? or anyone would do?
			// if (best_left > best_right) {
			cL = best_left_pos;
			S = best_left;
			// } else {
			// 	cR = best_right_pos;
			// 	S = best_right;
			// }
		} else if (best_left > S) {
			cL = best_left_pos;
			S = best_left;
		} else if (best_right > S) {
			cR = best_right_pos;
			S = best_right;
		} else {
			// best_left = S and best_right = S
			return false;
		}
	}
	assert(false);
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		cout << (solve() ? "YES\n" : "NO\n");
	}

	return 0;
}
