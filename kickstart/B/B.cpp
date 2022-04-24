/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 April 2022 04:39:11 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

bool pal(int u) {
	string S = to_string(u);
	string T = S;
	reverse(ALL(T));
	return T == S;
}

void solve() {
	int N, ans = 0;
	cin >> N;
	for (int d = 1; d * d <= N; d++) {
		if (N % d == 0) {
			int one = d, two = N / d;
			ans += pal(one);
			if (one != two)
				ans += pal(two);
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
