/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 May 2022 07:54:07 PM IST
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
	int S = 0;
	F0R(i, N) {
		cin >> A[i];
		S += A[i];
	}
	sort(A, A + N);
	reverse(A, A + N);
	using ld = long double;
	ld ans = 1. * S / N;
	int sum = 0;
	F0R(i, N - 1) {
		sum += A[i];
		int k = i + 2;
		ld get = sum + 1. * (S - sum) / (N - 1 - i);
		ans = max(ans, 1. * get / k);
	}
	cout << fixed << setprecision(10) << ans << '\n';
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
