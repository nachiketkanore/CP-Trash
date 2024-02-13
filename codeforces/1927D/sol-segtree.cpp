/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 13 February 2024 03:06:15 PM IST
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

const int MAX_N = 2e5 + 5;
int A[MAX_N];

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum;
	int mn_id, mx_id;

	node(int _mn, int _mx, int _sum, int _mn_id, int _mx_id) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
		mn_id = _mn_id;
		mx_id = _mx_id;
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
		if (left.mn < right.mn) {
			ret.mn = left.mn;
			ret.mn_id = left.mn_id;
		} else {
			ret.mn = right.mn;
			ret.mn_id = right.mn_id;
		}
		if (left.mx > right.mx) {
			ret.mx = left.mx;
			ret.mx_id = left.mx_id;
		} else {
			ret.mx = right.mx;
			ret.mx_id = right.mx_id;
		}
		ret.sum = left.sum + right.sum;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(A[L], A[L], A[L], L, L);
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

	node query(int l, int r) {
		return Query(1, 1, N, l, r);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, q, l, r;
	cin >> t;
	while (t--) {
		cin >> n;

		FOR(i, 1, n) cin >> A[i];
		segtree tree;
		tree.init(n);

		cin >> q;
		while (q--) {
			cin >> l >> r;
			node result = tree.query(l, r);
			if (result.mn == result.mx) {
				cout << "-1 -1\n";
			} else {
				int i = result.mn_id, j = result.mx_id;
				assert(A[i] ^ A[j]);
				cout << i << ' ' << j << '\n';
			}
		}
	}

	return 0;
}
