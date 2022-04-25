/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 April 2022 08:38:45 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum, id;

	node(int _mn, int _mx, int _sum, int _id) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
		id = _id;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
		id = -1;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		// build(1, 1, N);
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		if (left.mx > right.mx) {
			ret.id = left.id;
			ret.mx = left.mx;
		} else {
			ret.id = right.id;
			ret.mx = right.mx;
		}
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(0, 0, 0, -1);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if (j < L || i > R)
			return node();
		if (i <= L && R <= j)
			return st[u];
		int M = (L + R) / 2;
		node left = Query(u * 2, L, M, i, j);
		node right = Query(u * 2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if (L == R)
			return st[u];
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if (L == R) {
			// Point update
			// Update leaf value
			st[u] = node(val, val, val, L);
			return;
		}
		int M = (L + R) / 2;
		if (pos <= M)
			pUpdate(u * 2, L, M, pos, val);
		else
			pUpdate(u * 2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node query(int pos) {
		return pQuery(1, 1, N, pos);
	}

	node query(int l, int r) {
		return Query(1, 1, N, l, r);
	}

	void update(int pos, int val) {
		pUpdate(1, 1, N, pos, val);
	}
};

const int _ = 5e5 + 5;
int N, Q, tin[_], tout[_], tim, A[_];
vector<int> g[_];

void dfs(int u, int par) {
	tin[u] = ++tim;
	for (int v : g[u]) {
		if (v ^ par) {
			dfs(v, u);
		}
	}
	tout[u] = tim;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	FOR(i, 1, N) cin >> A[i];
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	segtree st;
	st.init(N);
	FOR(i, 1, N) {
		st.update(tin[i], A[i]);
	}
	while (Q--) {
		int type, u;
		cin >> type >> u;
		if (type == 1) {
			int x;
			cin >> x;
			st.update(tin[u], x);
		} else {
			int p, ans = 0;
			cin >> p;
			vector<node> removed;
			while (p--) {
				node get = st.query(tin[u], tout[u]);
				if (get.id >= tin[u] && get.id <= tout[u] && get.mx >= 1) {
					ans += get.mx;
					st.update(get.id, -1e9);
					removed.push_back(get);
				} else {
					ans = -1;
					break;
				}
			}
			cout << ans << '\n';
			for (auto nd : removed) {
				st.update(nd.id, nd.mx);
			}
		}
	}
	return 0;
}
