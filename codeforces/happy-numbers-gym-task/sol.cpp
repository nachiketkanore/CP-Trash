/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 20 July 2023 10:42:59 PM IST
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

const int MOD = 1e9 + 7;
string S;

const int MX = 1e6;
int cache[MX];
bool checker(int val) {
	if (val == 0) {
		return false;
	}
	if (~cache[val])
		return cache[val];
	int V = val;
	set<int> seen;

	while (val != 1 && !seen.count(val)) {
		seen.insert(val);
		int nval = 0;
		while (val > 0) {
			nval += (val % 10) * (val % 10);
			val /= 10;
		}
		val = nval;
	}
	return cache[V] = (val == 1);
}

int dp[2][205][50000];

int go(int id, int smt, int ssod) {
	if (id == sz(S)) {
		return checker(ssod);
	}
	int& ans = dp[smt][id][ssod];
	if (~ans)
		return ans;
	ans = 0;
	int curr = S[id] - '0';
	for (int dig = 0; dig <= (smt ? 9 : curr); dig++) {
		ans += go(id + 1, smt || (dig < curr), ssod + dig * dig);
		if (ans >= MOD)
			ans -= MOD;
	}
	return ans;
}

int check_for(const string& S) {
	int ssod = 0;
	for (char ch : S) {
		ssod += (ch - '0') * (ch - '0');
	}
	return checker(ssod);
}

int solve(string S) {
	::S = S;
	F0R(i, 2) F0R(j, sz(S)) F0R(k, 100 * sz(S)) dp[i][j][k] = -1;
	return go(0, 0, 0);
}

void solve() {
	string L, R;
	cin >> L >> R;
	int ans = (solve(R) - solve(L) + check_for(L) + MOD + MOD + MOD) % MOD;

	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
