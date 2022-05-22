/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 22 May 2022 02:25:15 PM IST
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

	sort(A, A + N);

	int ans = 0;

	for (int i = 0; i < N;) {
		int j = i + 1;

		while (j < N && A[i] == A[j]) {
			j++;
		}

		ans += (j - i) * i * (N - j);

		i = j;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;

	while (T--) {
		solve();
	}

	return 0;
}
