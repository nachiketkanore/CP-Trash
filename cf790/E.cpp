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

const int _ = 1e6;
int A[_];

void solve() {
	int N, Q;
	cin >> N >> Q;
	F0R(i, N + 1) A[i] = 0;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);
	FOR(i, 1, N) {
		A[i] += A[i - 1];
	}
	while (Q--) {
		int X;
		cin >> X;
		int ans = -1;
		int lo = 1, hi = N;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (A[mid] >= X) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << ans << '\n';
	}
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
