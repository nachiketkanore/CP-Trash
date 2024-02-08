/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 11:31:13 AM IST
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

string S;

class node {
	public:
	static const int inf = 1e18;
	int ans, open_extra, close_extra;

	node(int open_extra_, int close_extra_, int ans_) {
		ans = ans_;
		open_extra = open_extra_;
		close_extra = close_extra_;
	}

	node() {
		ans = open_extra = close_extra = 0;
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
		int common = min(left.open_extra, right.close_extra);
		ret.ans = left.ans + right.ans + common;
		ret.open_extra = left.open_extra + right.open_extra - common;
		ret.close_extra = left.close_extra + right.close_extra - common;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			if (S[L] == '(') {
				st[u] = node(1, 0, 0);
			} else {
				st[u] = node(0, 1, 0);
			}
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

	cin >> S;
	int N = sz(S);
	S = "$" + S;

	segtree st;
	st.init(N);

	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << (st.query(L, R).ans << 1) << '\n';
	}

	return 0;
}
