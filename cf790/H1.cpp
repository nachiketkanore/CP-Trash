/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, ans = 0;
	cin >> N;
	int A[N], cnt[N + 1];
	memset(cnt, 0, sizeof(cnt));

	F0R(i, N) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	F0R(j, N) {
		F0R(i, j) {
			if (A[i] > A[j])
				++ans;
		}
	}
	FOR(i, 1, N) {
		int tot = cnt[i];
		ans += tot * (tot - 1) / 2;
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
