/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 08:04:40 PM IST
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

int N, M;
bool vis[50][50];
vector<string> mat, nmat;

void dfs(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return;
	if (vis[i][j] || nmat[i][j] == '.')
		return;
	vis[i][j] = true;
	dfs(i - 1, j), dfs(i + 1, j), dfs(i, j - 1), dfs(i, j + 1);
}

bool check(vector<pair<int, int>> remove) {
	nmat = mat;
	memset(vis, false, sizeof(vis));
	for (auto [i, j] : remove)
		nmat[i][j] = '.';
	int connected = 0;
	F0R(i, N) F0R(j, M) if (!vis[i][j] && nmat[i][j] == '#') {
		connected += 1;
		dfs(i, j);
	}
	return connected > 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	mat.resize(N);
	int cnt = 0;
	for (auto& row : mat) {
		cin >> row;
		cnt += count(ALL(row), '#');
	}

	if (cnt <= 2) {
		cout << -1;
	} else {
		F0R(i, N) F0R(j, M) if (check({ make_pair(i, j) })) {
			cout << 1;
			return 0;
		}
		cout << 2;
	}
	/* F0R(i1, N) F0R(j1, M) F0R(i2, N) F0R(j2, M) {
		if (i1 != i2 && j1 != j2 && mat[i1][i2] == '#' && mat[i2][j2] == '#') {
			if (check({ make_pair(i1, j1), make_pair(i2, j2) })) {
				cout << 2;
				return 0;
			}
		}
	} */
	return 0;
}
