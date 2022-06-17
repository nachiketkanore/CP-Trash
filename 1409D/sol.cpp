/**
 *    Author: Nachiket Kanore
 *    Created: Friday 17 June 2022 08:11:26 PM IST
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

string N, out;
int S;
int_fast8_t dp[2][18][163];

bool go(int id, int sum, bool large_taken) {
	if (sum > S)
		return false;
	if (id == sz(N))
		return true;

	if (~dp[large_taken][id][sum])
		return dp[large_taken][id][sum];

	int_fast8_t& ans = dp[large_taken][id][sum];
	ans = 0;

	int lo = N[id] - '0', hi = 9;
	if (large_taken)
		lo = 0;

	FOR(dig, lo, hi) {
		ans |= go(id + 1, sum + dig, large_taken || (dig > N[id] - '0'));
	}
	return ans;
}

void trace(int id, int sum, bool large_taken) {
	if (sum > S)
		assert(0);
	if (id == sz(N))
		return;

	bool ans = go(id, sum, large_taken);
	assert(ans);
	int lo = N[id] - '0', hi = 9;
	if (large_taken)
		lo = 0;

	FOR(dig, lo, hi) {
		bool get = go(id + 1, sum + dig, large_taken || (dig > N[id] - '0'));
		if (get == ans) {
			out += (char)('0' + dig);
			return trace(id + 1, sum + dig, large_taken || (dig > N[id] - '0'));
		}
	}
}

void solve() {
	cin >> N >> S;
	memset(dp, -1, sizeof(dp));
	bool found = go(0, 0, false);
	out.clear();
	if (found) {
		trace(0, 0, false);
	} else {
		out = "1" + string(sz(N), '0');
	}
	int A = stoll(out);
	int B = stoll(N);
	cout << A - B << '\n';
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
