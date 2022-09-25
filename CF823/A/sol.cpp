/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 September 2022 08:06:46 PM IST
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
	int N, C;
	cin >> N >> C;
	map<int,int> cnt;
	FOR (i,1,N) {
		int o;
		cin >> o;
		cnt[o]++;
	}
	int ans = 0;
	for (auto [k, v]: cnt) {
		int one = C;
		int two = v;
		ans += min(one, two);
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
