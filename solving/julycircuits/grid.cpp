/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 July 2021 04:02:34 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>
#include <queue>

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 1010;
int n;
char mat[N][N];
bool vis[N][N];
vector<pair<int,int>> comp;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dfs_comp(int i, int j) {
	if (i < 1 || i > n || j < 1 || j > n) return;
	if (mat[i][j] == '#' || vis[i][j]) return;
	vis[i][j] = true;
	comp.push_back(make_pair(i, j));
	F0R (id,4) dfs_comp(i + dx[id], j + dy[id]);
}

const int M = 2e6;
int parent[M], dist[M];
bool vis2[M];
vector<int> graph[M];

vector<int> find_longest(int start, int n) {
	F0R (i,n) {
		parent[i] = dist[i] = -1;
		vis2[i] = false;
	}
	queue<int> Q;
	int who = start;
	Q.push(start);
	dist[start] = 0;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		vis2[u] = true;
		if (dist[who] < dist[u]) who = u;
		for (int v: graph[u]) {
			if (vis2[v]) continue;
			parent[v] = u;
			dist[v] = dist[u] + 1;
			Q.push(v);
		}
	}
	vector<int> ret;
	int PATH = 500;
	while (~who) {
		if (PATH-- == 0) break;
		ret.push_back(who);
		who = parent[who];
	}
	return ret; 
}



vector<pair<int,int>> find_path() {
	vector<pair<int,int>> ret;
	const int nodes = comp.size();
	F0R (i,nodes) graph[i].clear();
	sort(ALL(comp));

	F0R (i,nodes) {
		auto [x, y] = comp[i];
		F0R (id,4) {
			int nx = x + dx[id];
			int ny = y + dy[id];
			int j = lower_bound(ALL(comp), make_pair(nx, ny)) - comp.begin();
			if (j < nodes && comp[j] == make_pair(nx, ny)) {
				// add edge between i and j
				graph[i].push_back(j);
			}
		}
	}
	
	vector<int> starts;
	F0R (i,nodes) if (sz(graph[i]) <= 2) starts.push_back(i);

	int REP = 10;
	for (int start: starts) {
		if (REP-- == 0) break;
		vector<int> get_path = find_longest(start, nodes);
		if (sz(ret) < sz(get_path)) {
			ret.clear();
			F0R (i,sz(get_path)) {
				ret.push_back(comp[get_path[i]]);
			}
		}
		break;
	}

	return ret;
} 

int32_t main() {
	cin >> n;
	FOR (i,1,n) FOR (j,1,n) cin >> mat[i][j];
	vector<pair<int,int>> best_path;
	FOR (i,1,n) FOR (j,1,n) {
		if (mat[i][j] == '#' || vis[i][j]) continue;
		comp.clear();
		dfs_comp(i, j);
		vector<pair<int,int>> get_path = find_path();
		if (sz(best_path) < sz(get_path))
			swap(best_path, get_path);
	}
	cout << sz(best_path) << '\n';
	for (auto &[x, y]: best_path) {
		cout << x << ' ' << y << '\n';
	}
}
