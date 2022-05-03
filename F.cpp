/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 May 2022 05:42:40 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1001;
int N, M, Q, mat[_][_];

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
		st.resize((N << 2) + 2);
		build(1, 1, N);
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
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
			st[u] = node(val, val, val);
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Q;
	vector<segtree> cols(M + 1);
	segtree sum;
	sum.init(M);
	FOR(i, 1, M) {
		cols[i].init(N);
	}
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			char ch;
			cin >> ch;
			mat[i][j] = ch == '.';
			cols[j].update(i, mat[i][j]);
		}
	}
	FOR(j, 1, M) {
		int col_sum = cols[j].query(1, N).sum;
		sum.update(j, col_sum);
	}
	while (Q--) {
		int i, j;
		cin >> i >> j;
		if (mat[i][j] == 1) {
			mat[i][j] = 0;
			cols[j].update(i, mat[i][j]);
			int col_sum = cols[j].query(1, N).sum;
			sum.update(j, col_sum);
		} else {
			mat[i][j] = 1;
			cols[j].update(i, mat[i][j]);
			int col_sum = cols[j].query(1, N).sum;
			sum.update(j, col_sum);
		}
		int tot = N * M - sum.query(1, M).sum;
		int full_cols = tot / N;
		int ans = sum.query(1, full_cols).sum;
		int rem = tot % N;
		if (rem > 0) {
			assert(full_cols + 1 <= M);
			ans += cols[full_cols + 1].query(1, rem).sum;
		}
		cout << ans << '\n';
	}
	return 0;
}
