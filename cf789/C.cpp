/**
 *    Author: Solve Machine
 *    Created: Sunday 08 May 2022 08:03:40 PM IST
 **/
#include <bits/stdc++.h>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 5005;
int N, P[_], dp1[_][_], dp2[_][_];

int pref(int id, int val) {
	if (id < 1)
		return 0;
	int& ans = dp1[id][val];
	if (~ans)
		return ans;
	ans = 0;
	if (P[id] < val)
		ans = 1;
	ans += pref(id - 1, val);
	return ans;
}

int suff(int id, int val) {
	if (id > N)
		return 0;
	int& ans = dp2[id][val];
	if (~ans)
		return ans;
	ans = 0;
	if (P[id] < val)
		ans = 1;
	ans += suff(id + 1, val);
	return ans;
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		cin >> P[i];
		FOR(j, 1, N) {
			dp1[i][j] = dp2[i][j] = -1;
		}
	}

	long long ans = 0;
	FOR(b, 1, N) {
		FOR(c, b + 1, N) {
			ans += 1ll * suff(c + 1, P[b]) * pref(b - 1, P[c]);
		}
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
