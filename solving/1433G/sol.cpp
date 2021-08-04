/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 03:15:12 PM IST
(ツ) Silence is a fence around wisdom.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cassert>
#include <cstring>

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1002, inf = 1e8;

int n, m, u[N], v[N];
int minDist[N][N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int Q;
	cin >> n >> m >> Q;


	FOR (i,1,n) FOR (j,1,n) minDist[i][j] = inf, minDist[i][i] = 0;

	FOR (i,1,m) {
		cin >> u[i] >> v[i];
		int w;
		cin >> w;
		minDist[u[i]][v[i]] = w;
		minDist[v[i]][u[i]] = w;
	}

	FOR (k,1,n) FOR (i,1,n) FOR (j,1,n) minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);

	vector<pair<int,int>> queries;

	int ans = 0;

	FOR (i,1,Q) {
		int a, b;
		cin >> a >> b;
		ans += minDist[a][b];
		queries.push_back({a, b});
	}

	FOR (i,1,m) {
		int from = u[i], to = v[i];
		int cost = 0;

		for (auto [a, b] : queries) {
			int new_min = minDist[a][b];
			new_min = min(new_min, minDist[a][from] + minDist[to][b]);
			new_min = min(new_min, minDist[a][to] + minDist[b][from]);

			cost += new_min;
		}

		ans = min(ans, cost);
	}

	cout << ans << "\n";
}
