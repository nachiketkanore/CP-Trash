/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 August 2021 04:55:51 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int INF = 1e18;
const int N = 505;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
char mat[N][N];
bool vis[N][N];
int dist[N][N];
int H, W;

bool inside(int x, int y) {
	return 1 <= x && x <= H && 1 <= y && y <= W;
}

int32_t main() {
	cin >> H >> W;
	FOR(i, 1, H) {
		FOR(j, 1, W) {
			cin >> mat[i][j];
			dist[i][j] = INF;
		}
	}
	deque<pair<int, int>> Q;
	dist[1][1] = 0;
	Q.push_back(make_pair(1, 1));

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop_front();
		if (vis[x][y])
			continue;
		vis[x][y] = true;

		F0R(id, 4) {
			int nx = x + dx[id];
			int ny = y + dy[id];
			if (!inside(nx, ny))
				continue;
			if (dist[nx][ny] > dist[x][y] && mat[nx][ny] == '.') {
				dist[nx][ny] = dist[x][y];
				Q.push_front(make_pair(nx, ny));
			}
		}

		for (int cx = -2; cx <= 2; cx++) {
			for (int cy = -2; cy <= 2; cy++) {
				if (abs(cx) + abs(cy) >= 4)
					continue;
				int nx = x + cx;
				int ny = y + cy;
				if (!inside(nx, ny))
					continue;
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y] + 1;
					Q.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	int answer = dist[H][W];
	assert(answer ^ INF);
	cout << answer << '\n';
}
