/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 08:58:53 PM IST
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
	vector<int> A(N);
	for (int& x : A) {
		cin >> x;
	}
	bool ok = true;
	for (int i = 1; i < N; i++) {
		ok &= A[i - 1] % A[i] == 0;
	}
	cout << (ok ? "YES\n" : "NO\n");
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
