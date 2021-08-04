/*
Author: Nachiket Kanore
Created: Wednesday 06 January 2021 04:43:15 PM IST
(ツ) Patience is a virtue but you will never ever accomplish anything if you don't exercise action over patience.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

class Solution {
private:
	int n, Q, T = 0;
	vector<int> tin, tout;
	vector<vector<int>> g, xors_at_depth, timings_at_depth;
	vector< pair<int,int> > queries;
	vector<bool> answers;
	string s;	
public:
	Solution() {
		input();
		solve();
	}
	void input() {
		cin >> n >> Q;
		g.resize(n+1);
		tin.resize(n+1);
		tout.resize(n+1);
		xors_at_depth.resize(n+1);
		timings_at_depth.resize(n+1);
		queries.resize(Q);
		FOR (i,2,n) {
			int par;
			cin >> par;
			g[par].push_back(i);
		}
		cin >> s;
		s = " " + s;
		for (auto &[u, d] : queries) {
			cin >> u >> d;
		}
	}

	void dfs(int u, int dep) {
		tin[u] = ++T;
		timings_at_depth[dep].push_back(T);
		xors_at_depth[dep].push_back(1 << (s[u]-'a'));
		for (int v : g[u]) dfs(v, dep+1);
		tout[u] = T;
	}

	void solve() {
		dfs(1,1);
		FOR (dep,1,n) {
			for (int i = 1; i < sz(xors_at_depth[dep]); i++) {
				xors_at_depth[dep][i] ^= xors_at_depth[dep][i-1];
			}
		}
		for (auto [u, dep] : queries) {
			int from = lower_bound(ALL(timings_at_depth[dep]), tin[u]) - timings_at_depth[dep].begin();
			int to =   upper_bound(ALL(timings_at_depth[dep]), tout[u]) - timings_at_depth[dep].begin() - 1;
			int XOR = 0;
			int m = sz(xors_at_depth[dep]);
			if (0 <= to && to < m) XOR ^= xors_at_depth[dep][to];
			if (from > 0) XOR ^= xors_at_depth[dep][from-1];

			answers.push_back(__builtin_popcountll(XOR) <= 1);
		}
	}
	~Solution() {
		for (auto ans : answers)
			cout << (ans ? "Yes\n" : "No\n");
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	Solution S;
}
