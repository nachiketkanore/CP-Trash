/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 15 October 2022 07:38:01 PM IST
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

const int MX = 1e5 + 5;
const int INF = 1e18;
int N, E, x[MX], y[MX], c[MX];

int add_value(int i, int idir, int j, int jdir) {
	auto [cx, cy] = make_pair(x[i], y[i]);
	auto [nx, ny] = make_pair(x[j], y[j]);
	if (ny > cy)
		return -INF;
	if (cx < nx) {
		if (idir == 0 && jdir == 0) {
			return -2 * E;
		}
		if (idir == 0 && jdir == 1) {
			return -E;
		}
		if (idir == 1 && jdir == 0) {
			return -E;
		}
		if (idir == 1 && jdir == 1) {
			return 0;
		}
	} else if (cx > nx) {
		if (idir == 0 && jdir == 0) {
			return 0;
		}
		if (idir == 0 && jdir == 1) {
			return -E;
		}
		if (idir == 1 && jdir == 0) {
			return -E;
		}
		if (idir == 1 && jdir == 1) {
			return -2 * E;
		}
	} else {
		return idir != jdir;
	}
	assert(false);
}

int go(int curr, int done, bool dir) {

	int ans = 0;
	F0R(nxt, N) {
		if ((done >> nxt & 1) == 0) {
			F0R(ndir, 2) {
				ans = max(ans, c[curr] + add_value(curr, dir, nxt, ndir) + go(nxt, done | (1 << nxt), ndir));
			}
		}
	}
	ans = max(ans, c[curr]);
	return ans;
}

void solve() {
	cin >> N >> E;
	F0R(i, N) {
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	F0R(i, N) {
		ans = max(ans, go(i, 1 << i, 1));
		ans = max(ans, go(i, 1 << i, 0) - E);
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
