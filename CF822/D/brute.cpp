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

int N, K, A[100];

bool go(int L, int R, int curr) {
	if (curr < 0) return false;
	if (L == -1 || R == N) return true;
	return go(L - 1, R, curr + A[L]) | go(L, R + 1, curr + A[R]);
}

bool solve() {
	cin >> N >> K;
	K -= 1;
	F0R (i, N) cin >> A[i];
	return go(K - 1, K + 1, A[K]);
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
