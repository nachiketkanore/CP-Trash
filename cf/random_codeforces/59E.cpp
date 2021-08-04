/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 05:49:45 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <queue>
#include <set>
#include <array>
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

const int N = 3030, INF = 1e9;
vector<int> graph[N];
int n, m, k, dist[N];
set<array<int,3>> banned;
set<pair<int,int>> vis;

int32_t main() {
	cin >> n >> m >> k;
	FOR (i,1,m) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	FOR (i,1,k) {
		int a, b, c;
		cin >> a >> b >> c;
		banned.insert({a, b, c});
	}
	FOR (i,1,n) dist[i] = INF;
	queue<array<int,3>> Q;
	Q.push({0, 1, -1});
	dist[1] = 0;
	
	while (!Q.empty()) {
		auto [curr_dist, curr_node, prev_node] = Q.front();
		Q.pop();
		vis.insert({prev_node, curr_node});

		for (int to: graph[curr_node]) {
			if (banned.count({prev_node, curr_node, to})) continue;
			if (vis.count({curr_node, to})) continue;

			if (dist[to] > dist[curr_node] + 1) {
				dist[to] = dist[curr_node] + 1;
				Q.push({dist[curr_node] + 1, to, curr_node});	
			}
		}
	}

	int answer = dist[n];
	if (answer >= INF) answer = -1;
	cout << answer << '\n';
}
