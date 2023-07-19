/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 19 July 2023 09:48:51 PM IST
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int f[2];
	f[0] = f[1] = 0;
	for (char ch : s) {
		f[ch - '0']++;
	}
	s.clear();
	if (f[1]) {
		f[1]--;
		s += '1';
	}
	while (f[0]) {
		f[0]--;
		s += '0';
	}
	while (f[1]) {
		f[1]--;
		s += '1';
	}
	int pref = 0, ans = 0;
	for (char ch : s) {
		pref ^= (ch - '0');
		ans += pref;
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
