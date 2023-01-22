/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 09:48:15 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int N;
bool vis[2][2][2][2005][2005];
bool dp[2][2][2][2005][2005];

bool go(int x, char dx, int y, char dy, int who) {
	if (x == y)
		return who;
	if (vis[who][dx == 'L'][dy == 'L'][x][y])
		return dp[who][dx == 'L'][dy == 'L'][x][y];
	vis[who][dx == 'L'][dy == 'L'][x][y] = true;
	bool& yes = dp[who][dx == 'L'][dy == 'L'][x][y];
	yes = false;

	FOR(r, 1, 3) {
		// atleast one false
		// alice
		if (!who) {
			if (dx == 'L') {
				if (x - r >= 0)
					yes |= go(x - r, dx, y, dy, who ^ 1) == false;
				else
					yes |= go(r - x, 'R', y, dy, who ^ 1) == false;
			} else if (dx == 'R') {
				if (x + r <= N)
					yes |= go(x + r, dx, y, dy, who ^ 1) == false;
				else
					yes |= go(2 * N - x - r, 'L', y, dy, who ^ 1) == false;
			}
		}
		// bob
		else {
			if (dy == 'L') {
				if (y - r >= 0)
					yes |= go(x, dx, y - r, dy, who ^ 1) == false;
				else
					yes |= go(x, dx, r - y, 'R', who ^ 1) == false;
			} else if (dy == 'R') {
				if (y + r <= N)
					yes |= go(x, dx, y + r, dy, who ^ 1) == false;
				else
					yes |= go(x, dx, 2 * N - y - r, 'L', who ^ 1) == false;
			}
		}
	}
	return yes;
}

void solve() {
	memset(vis, false, sizeof(vis));
	memset(dp, false, sizeof(dp));
	int x, y;
	char dx, dy;
	cin >> N >> x >> y >> dx >> dy;
	bool win = go(x, dx, y, dy, 0);
	if (win) {
		cout << "Alice\n";
	} else {
		cout << "Bob\n";
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
