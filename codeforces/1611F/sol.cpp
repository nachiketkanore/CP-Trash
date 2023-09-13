/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 13 September 2023 10:08:55 PM IST
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
int N, A[_], S, P[_];

class node {
	public:
	static const int inf = 1e18;
	int mn, mx, sum;

	node() {
		// NOTE: update initial value
		mn = S;
		sum = S;
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
			st[u] = node();
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

void solve() {
	cin >> N >> S;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	segtree tree;
	tree.init(N);
	int ans = 0, l = -1, r = -1;

	for (int L = N; L; --L) {
		tree.update(L, N, A[L]);

		int best = -1;
		int lo = L, hi = N;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			int res = tree.query(L, mid).mn;

			if (res >= 0) {
				best = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		if (~best) {
			int len = best - L + 1;
			if (ans < len) {
				ans = len;
				l = L, r = best;
			}
		}
	}

	if (ans > 0) {
		cout << l << ' ' << r << '\n';
	} else {
		cout << "-1\n";
	}
}

void brute() {
	cin >> N >> S;
	FOR(i, 1, N) {
		cin >> A[i];
		P[i] = 0;
	}
	int ans = 0, l = -1, r = -1;
	for (int L = N; L; --L) {
		P[L] = S + A[L];
		FOR(id, L + 1, N) {
			P[id] += A[L];
		}
		int best = 0, last = L;
		FOR(id, L, N) {
			if (P[id] < 0)
				break;
			++best;
			last = id;
		}
		if (best > ans) {
			ans = best;
			l = L;
			r = last;
		}
	}
	if (ans > 0) {
		cout << l << ' ' << r << '\n';
	} else {
		cout << "-1\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
		// brute();
	}

	return 0;
}
