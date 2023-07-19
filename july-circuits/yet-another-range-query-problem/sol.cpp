/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 19 July 2023 10:23:28 PM IST
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

const int MX = 1e5 + 5;
int N, Q, A[MX];

class node {
	public:
	static const int inf = 1e18;
	vector<int> vals;

	node(int val) {
		vals.push_back(val);
	}

	node() {
		vals.clear();
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
		for (int add : left.vals) {
			ret.vals.push_back(add);
		}
		for (int add : right.vals) {
			ret.vals.push_back(add);
		}
		sort(ALL(ret.vals));
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(A[L]);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	int get_count(const vector<int>& node_vals, int L, int R) {
		int idr = upper_bound(ALL(node_vals), R) - node_vals.begin() - 1;
		int idl = lower_bound(ALL(node_vals), L) - node_vals.begin();
		if (idl <= idr)
			return idr - idl + 1;
		return 0;
		// int lo = 0, hi = sz(node_vals) - 1;
		// int r = -1;
		// while (lo <= hi) {
		// 	int mid = (lo + hi) / 2;
		// 	if (node_vals[mid] <= R) {
		// 		r = mid;
		// 		lo = mid + 1;
		// 	} else {
		// 		hi = mid - 1;
		// 	}
		// }
		// if (r == -1)
		// 	return 0;
		// assert(r < sz(node_vals));
		//
		// lo = 0, hi = sz(node_vals) - 1;
		// int l = -1;
		// while (lo <= hi) {
		// 	int mid = (lo + hi) / 2;
		// 	if (node_vals[mid] >= L) {
		// 		l = mid;
		// 		hi = mid - 1;
		// 	} else {
		// 		lo = mid + 1;
		// 	}
		// }
		// if (l == -1)
		// 	return 0;
		// assert(l >= 0);
		// assert(l < sz(node_vals));
		// assert(l <= r);
		// return r - l + 1;
	}

	int Query(int u, int L, int R, int i, int j, int QL, int QR) {
		if (j < L || i > R)
			return 0;
		if (i <= L && R <= j)
			return get_count(st[u].vals, QL, QR);
		int M = (L + R) / 2;
		return Query(u * 2, L, M, i, j, QL, QR) + Query(u * 2 + 1, M + 1, R, i, j, QL, QR);
	}

	int query(int l, int r) {
		return Query(1, 1, N, l, r, l, r);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	segtree st;
	st.init(N);
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << st.query(L, R) << '\n';
	}

	return 0;
}
