/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 22 May 2022 04:25:10 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int N, X, Y;
vector<int> subset;
vector<vector<bool>> vis;
vector<vector<bool>> dp;

bool go(int id, int rem) {
	if (rem < 0)
		return false;
	if (id == 0)
		return rem == 0;

	if (vis[id][rem])
		return dp[id][rem];
	vis[id][rem] = true;

	bool ans = false;
	ans |= go(id - 1, rem);
	ans |= go(id - 1, rem - id);

	dp[id][rem] = ans;
	return ans;
}

void trace(int id, int rem) {
	if (id == 0)
		return;

	bool ans = go(id, rem);
	if (ans == go(id - 1, rem)) {
		return trace(id - 1, rem);
	}
	if (ans == go(id - 1, rem - id)) {
		subset.push_back(id);
		return trace(id - 1, rem - id);
	}
	assert(0);
}

void solve() {
	cin >> N >> X >> Y;
	int tot = N * (N + 1) / 2;
	if ((X * tot) % (X + Y) != 0) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	cout << "POSSIBLE\n";
	subset.clear();
	int Sa = (X * tot) / (X + Y);
	// int Sb = tot - Sa;
	for (int i = N; i >= 1; i--) {
		if (i <= Sa) {
			subset.push_back(i);
			Sa -= i;
		}
	}
	assert(Sa == 0);
	cout << sz(subset) << '\n';
	for (int x : subset) {
		cout << x << ' ';
	}
	cout << '\n';

	/* bool first = true;
	int small = 0;
	if (Sa < Sb) {
		small = Sa;
		first = true;
	} else {
		small = Sb;
		first = false;
	}

	vis = vector<vector<bool>>(N + 1, vector<bool>(small + 1, false));
	dp = vector<vector<bool>>(N + 1, vector<bool>(small + 1, false));

	bool ans = go(N, small);
	assert(ans);

	cout << "POSSIBLE\n";
	subset.clear();
	trace(N, small);
	vector<int> other;
	sort(ALL(subset));
	FOR(i, 1, N) if (!binary_search(ALL(subset), i)) other.push_back(i);

	if (first) {
		cout << sz(subset) << '\n';
		for (int x : subset) {
			cout << x << " ";
		}
		cout << '\n';
	} else {
		cout << sz(other) << '\n';
		for (int x : other) {
			cout << x << " ";
		}
		cout << '\n';
	} */
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
