/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 May 2022 07:54:19 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N;
	cin >> N;
	int A[N];
	F0R(i, N) cin >> A[i];
	int ans = 0;
	bool bad = false;
	for (int i = N - 2; i >= 0; i--) {
		int nxt = A[i + 1];
		while (A[i] >= nxt && A[i] > 0) {
			A[i] >>= 1;
			ans++;
		}
		if (A[i] >= nxt) {
			bad = true;
		}
	}
	if (bad)
		ans = -1;
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
