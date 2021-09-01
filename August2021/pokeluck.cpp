/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 31 August 2021 11:02:38 PM IST
**/
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N + 1);
	FOR (i,1,M) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	const int INF = 1e9;
	vector<bool> vis(N + 1, false);
	vector<int> dist(N + 1, INF);
	queue<int> Q;
	Q.push(1);
	dist[1] = 0;
	while (Q.size()) {
		int u = Q.front();
		Q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int v: g[u]) {
			cmin(dist[v], dist[u] + 1);
			Q.push(v);
		}
	}
	FOR (i,2,N) cout << dist[i] << "\n";
}
