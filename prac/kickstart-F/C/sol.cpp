/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 September 2022 10:27:31 PM IST
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

struct vegie {
	int q, l, v;
};

int D, N, X;
vector<vegie> A;
int dp[20][1 << 15];

int go(int mask, int day) {
	if (day > N)
		return 0;
	int& ans = dp[day][mask];
	if (~ans)
		return ans;
	ans = 0;
	F0R(j, N) {
		if (mask >> j & 1)
			continue;
		bool can = day + A[j].l - 1 < D;
		if (can) {
			ans = max(ans, A[j].v + go(mask | (1 << j), day + 1));
		}
	}
	return ans;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> D >> N >> X;
	A.resize(N);
	for (vegie& v : A) {
		cin >> v.q >> v.l >> v.v;
	}
	int ans = go(0, 1);
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
