/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 06 November 2022 08:14:01 PM IST
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
	int N;
	cin >> N;
	string S;
	cin >> S;
	int z = 0, o = 0;
	F0R(i, N) {
		z += S[i] == '0';
		o += S[i] == '1';
	}
	int ans = z * o;
	for (int i = 0; i < N;) {
		int j = i, cnt = 0;
		while (j < N && S[j] == S[i]) {
			j++;
			cnt++;
		}
		ans = max(ans, cnt * cnt);
		i = j;
	}
	cout << ans << '\n';
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
