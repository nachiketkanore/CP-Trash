/*
Author: Nachiket Kanore
Created: Sunday 07 February 2021 12:19:57 PM IST
(ツ) Arriving at one point is the starting point to another.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 1e6 + 6, inf = 1e18;
const int LOG = 21;

int n, a[N];

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
		// build(1,1,N);
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
			lazy[u * 2] = lazy[u];
			lazy[u * 2 + 1] = lazy[u];
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum = (R - L + 1) * lazy[u];
			st[u].mx = lazy[u];
			st[u].mn = lazy[u];
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}

	// void build (int u, int L, int R) {
	// 	if(L == R) {
	// 		// Leaf value
	// 		st[u] = node(a[L], a[L], a[L]);
	// 		return;
	// 	}
	// 	int M = (L + R)/2;
	// 	build(u*2, L, M);
	// 	build(u*2 + 1, M + 1, R);
	// 	merge(st[u], st[u*2], st[u*2+1]);
	// }

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
	int Q;
	cin >> n >> Q;
	segtree T[LOG + 1];
	FOR(i, 0, LOG) T[i].init(n);
	FOR(i, 1, n) {
		cin >> a[i];
		int setbits = __builtin_popcountll(a[i]);
		T[setbits].update(i, 1);
	}

	auto get_id = [&](int which, int L, int R) {
		int ret = -1;
		int lo = L, hi = R;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (T[which].query(L, mid).sum >= 1) {
				ret = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return ret;
	};

	FOR(i, 1, Q) {
		int type;
		cin >> type;
		if (type == 1) {
			int L, R, val;
			cin >> L >> R >> val;
			val = __builtin_popcountll(val);
			int diff = inf, best = -1;
			for (int bit = 0; bit < LOG; bit++) {
				int id = get_id(bit, L, R);
				if (~id)
					if (cmin(diff, abs(bit - val)))
						best = id;
			}

			assert(~best);
			cout << best << '\n';
		} else {
			int L, R;
			cin >> L >> R;
			for (int bit = 0; bit <= 10; bit++) {
				T[bit].update(L, R, 0);
				T[20 - bit].update(L, R, 1);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;
	FOR(tt, 1, T) {
		cout << "Case " << tt << ":\n";
		solve();
	}
}
