/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 08:31:19 PM IST
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
	cin >> N;
	char ch;
	cin >> ch;
	string S;
	cin >> S;
	vector<int> pos[26];
	F0R(i, N) {
		pos[S[i] - 'a'].push_back(i);
		pos[S[i] - 'a'].push_back(N + i);
	}
	F0R(ch, 26) {
		sort(ALL(pos[ch]));
	}
	int ans = -1;
	F0R(start, N) {
		if (S[start] != ch)
			continue;
		const vector<int>& srch = pos['g' - 'a'];
		int id = lower_bound(ALL(srch), start) - srch.begin();
		assert(id >= 0 && id < sz(srch));
		int nxt = srch[id];
		// see(start, nxt);
		ans = max(ans, nxt - start);
	}
	assert(~ans);
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
