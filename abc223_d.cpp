/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 21 October 2021 03:12:16 PM IST
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
#include <set>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

pair<bool, vector<int>> topo_sort(vector<vector<int>> graph) {
	const int N = graph.size();
	vector<int> in(N);
	F0R (i,N) {
		for (int to: graph[i]) {
			in[to]++;
		}
	}
	set<int> Q;
	F0R (i,N) {
		if (in[i] == 0) {
			Q.insert(i);
		}
	}
	vector<int> order;
	while (!Q.empty()) {
		int u = *Q.begin(); Q.erase(Q.find(u));
		order.push_back(u);
		for (int v: graph[u]) {
			in[v]--;
			if (in[v] == 0) {
				Q.insert(v);
			}
		}
	}
	bool found = sz(order) == N;
	return make_pair(found, order);
}

int32_t main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> graph(N);
	F0R (i,M) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
	}
	auto [exists, order] = topo_sort(graph);
	if (!exists) {
		cout << "-1\n";
	} else {
		for (int x: order) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
}
