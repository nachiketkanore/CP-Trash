/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 November 2022 08:41:35 PM IST
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
	int ans = 0;
	cin >> N;
	vector<int> A(N);
	F0R(i, N) {
		cin >> A[i];
		if (i)
			A[i] += A[i - 1];
	}

	map<int, int> freq;
	int mx = 0;
	for (int i = N - 1; ~i; --i) {
		freq[A[i]]++;
		mx = max(mx, freq[A[i]]);
		if (A[i] - (i ? A[i - 1] : 0) == 0) {
			ans += mx;
			freq.clear();
			mx = 0;
		}
	}
	ans += freq[0];

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
