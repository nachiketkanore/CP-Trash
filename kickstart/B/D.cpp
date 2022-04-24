/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 April 2022 06:23:55 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 505;
bool mat[_][_], vis[_][_];
int N, M;
string ans;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
const char p[] = { 'E', 'S', 'W', 'N' };
// const char p[] = { 'R', 'D', 'L', 'U' };

bool inside(int i, int j) {
	return 1 <= i && i <= N && 1 <= j && j <= M;
}

void dfs(int i, int j) {
	vis[i][j] = true;
	F0R(id, 4) {
		int ni = i + dx[id];
		int nj = j + dy[id];
		if (inside(ni, nj) && !vis[ni][nj]) {
			if (mat[ni][nj])
				continue;
			ans += p[id];
			dfs(ni, nj);
		}
	}
}

void solve() {
	ans.clear();
	int R, C;
	cin >> R >> C;
	N = 2 * R, M = 2 * C;
	memset(mat, 0, sizeof(mat));
	memset(vis, 0, sizeof(vis));
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			char ch = '#';
			cin >> ch;
			// #warning check
			// ch = '#';
			// if (i % 2 == 0 && j % 2 == 0) {
			mat[2 * i - 1][2 * j - 1] = ch == '#';
			mat[2 * i - 1][2 * j] = ch == '#';
			mat[2 * i][2 * j - 1] = ch == '#';
			mat[2 * i][2 * j] = ch == '#';
			// }
		}
	}
	// FOR(i, 1, N) {
	// 	FOR(j, 1, M) {
	// 		cout << mat[i][j] << " \n"[j == M];
	// 	}
	// }
	dfs(1, 1);
	ans += "N";
	bool bad = false;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			if (mat[i][j] == 0 && vis[i][j] == 0) {
				bad = true;
			}
		}
	}
	if (bad)
		ans = "IMPOSSIBLE";
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
