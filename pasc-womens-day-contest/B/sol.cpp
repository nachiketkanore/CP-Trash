/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 March 2023 11:48:12 PM IST
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

const int _ = 1e5 + 5;
string S;
int N, Q, pref[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	N = sz(S);
	S = "$" + S;
	FOR(i, 1, N - 1) {
		pref[i] = S[i] == S[i + 1];
		pref[i] += pref[i - 1];
	}
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << pref[R - 1] - pref[L - 1] << '\n';
	}

	return 0;
}
