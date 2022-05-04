/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 May 2022 11:33:07 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, sum = 0, ans = 0;
	cin >> N;
	int A[N];
	F0R(i, N) {
		cin >> A[i];
		sum += A[i];
		A[i] *= N;
	}
	map<int, int> freq;
	F0R(i, N) {
		ans += freq[2 * sum - A[i]];
		freq[A[i]]++;
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
