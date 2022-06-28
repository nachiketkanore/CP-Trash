/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 28 June 2022 10:33:41 PM IST
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
	string S;
	cin >> S;
	int ans = 1;
	vector<int> cnt(26);
	for (char ch : S) {
		cnt[ch - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		int f = 1;
		for (int j = 1; j <= cnt[i]; j++) {
			f *= j;
		}
		ans *= f;
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
