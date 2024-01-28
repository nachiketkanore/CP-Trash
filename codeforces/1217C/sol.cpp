/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 01:02:41 PM IST
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
	string S;
	cin >> S;
	const int N = S.size();
	int zeros[N];
	zeros[0] = S[0] == '0';
	FOR(i, 1, N - 1) {
		if (S[i] == '0')
			zeros[i] = 1 + zeros[i - 1];
		else
			zeros[i] = 0;
	}

	int answer = 0;
	FOR(L, 0, N - 1) if (S[L] == '1') {
		int val = 0;
		FOR(R, L, min(N - 1, L + 20)) {
			val = val * 2 + (S[R] - '0');
			if (val == R - L + 1) {
				answer++;
			}
			if (L > 0 && zeros[L - 1] > 0) {
				int idx = L - zeros[L - 1];
				int j = R + 1 - val;
				if (idx <= j && j < L)
					++answer;
			}
		}
	}

	cout << answer << '\n';
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
