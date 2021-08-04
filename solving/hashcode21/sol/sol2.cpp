/* HashCode 2021 - Nachiket Kanore (Team: Pretests Passed) */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r){
    std::uniform_int_distribution<int> uid(l, r); return uid(rng);
}

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct edge {
	int to, w;
	string name;
	edge(int to_, int w_, string name_) {
		to = to_;
		w = w_;
		name = name_;
	}
};

const int N = 1e5 + 5;
int tot_time, n, e, cars, bonus;
vector<edge> to[N], from[N];
map<string, int> cnt_edge;
map<string, array<int,3>> connection;
vector<pair<string, int>> ans_nodes[N];
		// road / green
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> tot_time >> n >> e >> cars >> bonus;
	for (int i = 0; i < e; i++) {
		int u, v, req;	cin >> u >> v;
		string name;	cin >> name >> req;
		to[u].push_back(edge(v, req, name));
		connection[name] = {u, v, req};
		from[v].push_back(edge(u, req, name));	// reverse edge just for finding incoming edges
	}


	for (int i = 0; i < cars; i++) {
		int path_len;	cin >> path_len;
		string name;
		while (path_len--) {
			cin >> name;
			cnt_edge[name]++;
			if (connection.count(name)) {
				array<int,3> uvw = connection[name];
				ans_nodes[uvw[1]].push_back({name, uvw[2]});
			}
			
		}
	}


	vector<int> perm;
	for (int i = 0; i < n; i++)
		if (sz(ans_nodes[i]))
			perm.push_back(i);

	cout << sz(perm) << '\n';
	for (int i : perm) {
		cout << i << '\n';
		map<string, int> green;

		for (auto [name, green_time] : ans_nodes[i])
			green[name] = green_time;
		cout << sz(green) << '\n';
		for (auto [name, green_time] : green)
			cout << name << ' ' << rand(1, 2) << '\n';
	}
}

/*
3
1
2
rue-d-athenes 2
rue-d-amsterdam 1
0
1
rue-de-londres 2
2
1
rue-de-moscou 1
*/