/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 05:55:16 PM IST
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

const int _ = 2e5 + 5;
int N, M, A[_];

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum;
	int prod;

	node(int _mn, int _mx, int _sum, int _prod) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
		prod = _prod;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
		prod = 1;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N, mod;
	vector<node> st;
	void init(int n, int _mod) {
		N = n;
		st.resize((N << 2) + 2);
		build(1, 1, N);
		mod = _mod;
	}

	// Write reqd merge functions
	void merge(node& ret, node& left, node& right) {
		// ret.prod = (left.prod * right.prod) % mod;
		ret.prod = (left.prod * right.prod) % mod;
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(0, 0, 0, A[L]);
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

void solve() {
	cin >> N >> M;
	FOR(i, 1, N) cin >> A[i];
	segtree tree;
	tree.init(N, M);
	int L = 1, R = N;
	string S;
	cin >> S;
	for (char ch : S) {
		int ans = (tree.query(L, R).prod);
		see(L, R, ans);
		cout << ans << ' ';
		if (ch == 'L')
			++L;
		if (ch == 'R')
			--R;
	}
	cout << '\n';
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
