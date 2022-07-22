/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 July 2022 01:59:29 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast8_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

struct State {
	string S;
	int dist;
	int zi, zj;
	State(vector<vector<int>>& mat) {
		dist = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				S += (char)(mat[i][j] + '0');
				if (mat[i][j] == 0) {
					zi = i;
					zj = j;
				}
			}
		}
	}
};

int solve(vector<vector<int>>& mat) {
	queue<State> Q;
	Q.push(State(mat));
	string want;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			want += (char)((i * 3 + j) + '0');
	map<string, bool> vis;

	while (!Q.empty()) {
		State curr = Q.front();
		Q.pop();

		if (curr.S == want) {
			return curr.dist;
		}

		if (vis.count(curr.S))
			continue;
		vis[curr.S] = true;

		for (int id = 0; id < 4; id++) {
			int ni = curr.zi + dx[id];
			int nj = curr.zj + dy[id];
			if (ni < 0 || nj < 0 || ni >= 3 || nj >= 3)
				continue;
			State nxt = curr;
			int x = curr.zi * 3 + curr.zj;
			int y = ni * 3 + nj;
			swap(nxt.S[x], nxt.S[y]);
			if (vis.count(nxt.S))
				continue;
			nxt.dist = curr.dist + 1;
			nxt.zi = ni;
			nxt.zj = nj;
			Q.push(nxt);
		}
	}

	return -1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> mat = { { 1, 0, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };
	cout << solve(mat) << '\n';

	return 0;
}
