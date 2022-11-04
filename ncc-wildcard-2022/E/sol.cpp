/**
 *    Author: Nachiket Kanore
 *    Created: Monday 31 October 2022 08:03:38 PM IST
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

const int INF = 1e18;

void solve() {
	int N, K;
	cin >> N >> K;
	int A[N];
	F0R(i, N) cin >> A[i];
	if (N < 5000) {
		int ans = -INF;
		F0R(i, N) {
			int s = 0;
			for (int j = i; j - i + 1 <= K && j < N; j++) {
				s += A[j];
				ans = max(ans, s);
			}
		}
		cout << ans << '\n';
		return;
	}
	int s = 0;
	int mx = -INF;
	deque<int> pref;
	multiset<int> prefs;
	int ans = -INF;
	F0R(i, N) {
		int u = A[i];
		mx = max(mx, u);
		s += u;
		if (i + 1 <= K) {
			ans = max(ans, s);
		}
		// see(i, s);
		// for (int x : prefs) {
		// 	cout << x << ' ';
		// }
		// cout << '\n';
		// see(i, s, best);
		if (sz(prefs)) {
			int best = *prefs.begin();
			// see(best);
			ans = max(ans, s - best);
		}
		prefs.insert(s);
		pref.push_back(s);
		if (sz(prefs) > K) {
			int rem = pref.front();
			pref.pop_front();
			prefs.erase(prefs.find(rem));
			// see("removed", rem);
		}
	}
	if (K == 0) {
		ans = 0;
	} else {
		ans = max(ans, mx);
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
