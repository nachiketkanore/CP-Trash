/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 08:53:51 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

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

struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n) {
		N = n;
		st.resize((N << 2) + 2);
		cLazy.assign((N << 2) + 2, false);
		lazy.assign((N << 2) + 2, 0);
		build(1, 1, N);
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}

	// Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u * 2] = 1;
			cLazy[u * 2 + 1] = 1;

			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u * 2] += lazy[u];
			lazy[u * 2 + 1] += lazy[u];
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum += (R - L + 1) * lazy[u];
			st[u].mx += lazy[u];
			st[u].mn += lazy[u];
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(0, 0, 0);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if (cLazy[u])
			propagate(u, L, R);
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
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R)
			return st[u];
		int M = (L + R) / 2;
		if (pos <= M)
			return pQuery(u * 2, L, M, pos);
		else
			return pQuery(u * 2 + 1, M + 1, R, pos);
	}

	void Update(int u, int L, int R, int i, int j, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j < L || i > R)
			return;
		if (i <= L && R <= j) {
			// Default range update operation is :
			// adding val to all elements in range [...]
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R) / 2;
		Update(u * 2, L, M, i, j, val);
		Update(u * 2 + 1, M + 1, R, i, j, val);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (L == R) {
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
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

	void update(int l, int r, int val) {
		Update(1, 1, N, l, r, val);
	}
};
struct Query {
	int l, r, c, id;
	Query(int l, int r, int c, int id) : l(l), r(r), c(c), id(id) {
	}
	Query() {
	}
};

const int MX = 2e5 + 5;
int N, ans[MX];

void solve() {
	cin >> N;
	vector<vector<Query>> queries(N);
	vector<Query> Q(N);
	vector<int> pts;
	F0R(i, N) {
		int l, r, c;
		cin >> l >> r >> c;
		--c;
		Q[i] = Query(l, r, c, i);
		pts.push_back(l);
		pts.push_back(r);
		queries[c].push_back(Q[i]);
	}
	sort(ALL(pts));

	multiset<int> points;
	segtree st;
	st.init(4 * N);

	auto get_compressed_pt = [&](int x) { return lower_bound(ALL(pts), x) - pts.begin() + 1; };

	F0R(i, N) {
		int L = get_compressed_pt(Q[i].l), R = get_compressed_pt(Q[i].r);
		st.update(L, R, +1);
		points.insert(Q[i].l);
		points.insert(Q[i].r);
	}
	const int INF = 1e12;

	auto get_best_distance = [&](int x) {
		int best = INF;
		auto it = points.lower_bound(x);
		if (it != points.end()) {
			best = min(best, abs(x - *it));
		}
		if (it != points.begin()) {
			--it;
			best = min(best, abs(x - *it));
		}
		return best;
	};

	F0R(col, N) {
		// removing all segments with color col
		for (Query q : queries[col]) {
			int L = get_compressed_pt(q.l), R = get_compressed_pt(q.r);
			st.update(L, R, -1);
			points.erase(points.find(q.l));
			points.erase(points.find(q.r));
		}
		// computing answer for all segments with color col
		for (Query q : queries[col]) {
			// check intersecting
			int L = get_compressed_pt(q.l), R = get_compressed_pt(q.r);
			if (st.query(L, R).sum) {
				ans[q.id] = 0;
			} else {
				int best = INF;
				best = min(best, get_best_distance(q.l));
				best = min(best, get_best_distance(q.r));
				ans[q.id] = best;
			}
		}
		// inserting back all segments with color col
		for (Query q : queries[col]) {
			int L = get_compressed_pt(q.l), R = get_compressed_pt(q.r);
			st.update(L, R, +1);
			points.insert(q.l);
			points.insert(q.r);
		}
	}

	F0R(i, N) {
		cout << ans[i] << " \n"[i == N - 1];
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
