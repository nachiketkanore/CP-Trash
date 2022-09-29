/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 29 September 2022 08:13:04 PM IST
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

int N, d[105];
map<int, int> dp[105];

int go(int id, int prev) {
	if (id == N + 1) return 1;
	if (dp[id].count(prev)) return dp[id][prev];
	int ans = 0;
	set<int> chk = {prev - d[id], prev + d[id]};
	for (int curr: chk) {
		if (curr >= 0) {
			ans += go(id + 1, curr);
			if (ans > 2) break;
		}
	}
	if (ans > 2) ans = 2;
	dp[id][prev] = ans;
	return ans;
}

void trace(int id, int prev) {
	if (id == N + 1) return;
	int ans = go(id, prev);
	set<int> chk = {prev - d[id], prev + d[id]};
	for (int curr: chk) {
		if (curr >= 0) {
			if(go(id + 1, curr)) {
				cout << curr << ' ';
				return trace(id + 1, curr);
			}
		}
	}
	assert(false);
}

void solve() {
	cin >> N;
	FOR (i,1,N) {
		cin >> d[i];
		dp[i].clear();
	}
	if (N == 1) {
		cout << d[1] << "\n";
		return;
	}
	int tot = go(2, d[1]);
	if (tot > 1) {
		cout << "-1\n";
	} else {
		cout << d[1] << ' ';
		trace(2, d[1]);
		cout << '\n';
	}
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
