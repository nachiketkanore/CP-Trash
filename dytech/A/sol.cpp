/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 October 2022 08:10:17 PM IST
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
	int N, K;
	cin >> N >> K;
	string S; cin >> S;
	int f[26] = {0};
	for (char ch: S) {
		f[ch-'a']++;
	}
	string ans;
	F0R (i,K) {
		int take = N / K;
		int curr = 0;
		while (take--) {
			if (f[curr] > 0) {
				f[curr]--;
				curr++;
			} else {
				break;
			}
		}
		ans += (char)('a' + curr);
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
