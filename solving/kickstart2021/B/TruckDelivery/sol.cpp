/*
Author: Nachiket Kanore
Created: Monday 19 April 2021 11:11:08 AM IST
*/
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

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

class node {
public:
	static const int inf = 1e18;
	int mn, mx, sum;

	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = __gcd(left.sum, right.sum);
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(0,0,0);
			return;
		}
		int M = (L + R)/2;
		build(u*2, L, M);
		build(u*2 + 1, M + 1, R);
		merge(st[u], st[u*2], st[u*2+1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if(j<L || i>R)
			return node();
		if(i<=L && R<=j)
			return st[u];
		int M = (L + R)/2;
		node left = Query(u*2, L, M, i, j);
		node right = Query(u*2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if(L == R)
			return st[u];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(u*2, L, M, pos);
		else
			return pQuery(u*2 + 1, M + 1, R, pos);
	}	

	void pUpdate(int u, int L, int R, int pos, int val) {
		if(L == R) {
			// Point update
			// Update leaf value
			st[u] = node(val, val, val);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(u*2, L, M, pos, val);
		else
			pUpdate(u*2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }
} T;

struct edge {
	int to;
	int w;
	int a;
	edge(int to, int w, int a) : to(to), w(w), a(a) {}
};

int n, q;
vector<pair<int,int>> queries[N];
int answers[N];
vector<edge> g[N];

void dfs(int u, int par) {
	for (auto [w, id] : queries[u]) {
		answers[id] = T.query(1, w).sum;
	}
	for (edge e : g[u]) {
		if (e.to == par) continue;
		T.update(e.w, e.a);
		dfs(e.to, u);
		T.update(e.w, 0);
	}
}

void solve() {
	T.init(N);
	cin >> n >> q;
	FOR (i,1,n) {
		g[i].clear();
		queries[i].clear();
	}
	FOR (i,1,n-1) {
		int u, v, w, a;
		cin >> u >> v >> w >> a;
		g[u].push_back(edge(v, w, a));
		g[v].push_back(edge(u, w, a));
	}
	FOR (i,1,q) {
		int node, w;
		cin >> node >> w;
		queries[node].push_back(make_pair(w, i));
	}
	dfs(1,1);
	FOR (i,1,q) cout << answers[i] << " \n"[i==q];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int Tc; cin >> Tc;
	FOR (tc,1,Tc) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
