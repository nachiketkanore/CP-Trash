/*
Author: Nachiket Kanore
Created: Tuesday 05 January 2021 01:31:28 PM IST
(ツ) Stay away from what might have been and look at what will be.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int inf = 1e18;
int H, W;
int mat[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[401][401];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> H >> W;
	FOR (i,1,H) {
		FOR (j,1,W) {
			char ch;
			cin >> ch;
			if (ch == '.')
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}	

	FOR (i,1,400) FOR (j,1,400) dist[i][j] = (i == j ? 0 : inf);

	auto node = [&](int i, int j) { return (i-1) * W + j; };

	FOR (i,1,H) {
		FOR (j,1,W) if (mat[i][j]) {
			FOR (k,0,3) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (1 <= ni && ni <= H && 1 <= nj && nj <= W && mat[ni][nj]) {
					dist[node(i, j)][node(ni, nj)] = 1;
				}
			}
		}
	}

	int ans = 0;
	int N = H * W;
	FOR (k,1,N) FOR (i,1,N) FOR (j,1,N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	FOR (i1,1,H) FOR (j1,1,H) FOR (i2,1,W) FOR (j2,1,W) if (mat[i1][j1] && mat[i2][j2]) cmax(ans, dist[node(i1, j1)][node(i2, j2)]);

	cout << ans << '\n';
}
