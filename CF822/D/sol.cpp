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
	int N, K; cin >> N >> K;
	vector<int> A(N + 1);
	FOR (i,1,N) {
		cin >> A[i];
	}
	int S = A[K];
	int cL = K, cR = K;
	while (true) {
		assert(S >= 0);
		if (cL == 1 || cR == N) return true;
		int L = cL - 1;
		int final_left = S;
		while (L >= 1 && final_left + A[L] >= 0) {
			final_left += A[L];
			L -= 1;
		}
		L++;

		int R = cR + 1;
		int final_right = S;
		while (R <= N && final_right + A[R] >= 0) {
			final_right += A[R];
			R += 1;
		}
		R--;
		
		if (L == 1 || R == N) return true;
		// cannot extend anywhere
		if (cL == L && cR == R) return false;
		// see(L, R, cL, cR, S);
		// see(final_left, final_right);

		if (L == cL) {
			S = final_right;
			cR = R;
		} else if (R == cR) {
			S = final_left;
			cL = L;
		} else {
			if (final_left > final_right) {
				S = final_left;
				cL = L;
			} else {
				S = final_right;
				cR = R;
			}
		}
		// see("now", cL, cR);
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
