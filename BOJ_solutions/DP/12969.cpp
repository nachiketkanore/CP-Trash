#include "bits/stdc++.h"

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

int n, k;
bool dp[30][31][31][30 * 15];
bool vis[30][31][31][30 * 15];

int go(int id, int a, int b, int rem) {
	if (rem < 0)
		return 0;
	if (id == n)
		return rem == 0;

	if (vis[id][a][b][rem])
		return dp[id][a][b][rem];

	int ans = 0;

	for (int ch = 0; ch < 3; ch++) {
		int take = 0;
		if (ch == 2)
			take = a + b;
		if (ch == 1)
			take = a;
		ans |= go(id + 1, a + (ch == 0), b + (ch == 1), rem - take);
	}
	dp[id][a][b][rem] = ans;
	return ans;
}

void trace(int id, int a, int b, int rem) {
	if (rem < 0)
		assert(0);
	if (id == n) {
		assert(!rem);
		return;
	}

	int ans = go(id, a, b, rem);

	for (int ch = 0; ch < 3; ch++) {
		int take = 0;
		if (ch == 2)
			take = a + b;
		if (ch == 1)
			take = a;
		int get = go(id + 1, a + (ch == 0), b + (ch == 1), rem - take);

		if (get == ans) {
			cout << (char)('A' + ch);
			return trace(id + 1, a + (ch == 0), b + (ch == 1), rem - take);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int cnt = go(0, 0, 0, k);
	if (!cnt)
		cout << -1;
	else
		trace(0, 0, 0, k);
}