/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 10:03:16 PM IST
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

const int MAX = 5e5 + 5;
int N;

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

void solve() {
	cin >> N;
	N /= 2;
	vector<int> A(N + 1), B(N + 1);
	set<int> have;
	FOR(i, 1, N) {
		cin >> A[i];
		if (have.count(A[i])) {
			cout << "-1\n";
			return;
		}
		have.insert(A[i]);
	}

	int id = 0;
	FOR(val, 1, 2 * N) {
		if (!have.count(val)) {
			B[++id] = val;
		}
	}
	assert(id == N);
	segtree st;
	st.init(N);

	// see(A);
	// see(B);
	FOR(i, 1, N) {
		if (A[i] < B[i]) {
			st.update(i, 1);
		}
	}

	FOR(i, 1, N) {
		if (A[i] > B[i]) {
			continue;
		}
		int lo = i + 1, hi = N;
		int id = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int sum = st.query(i, mid).sum;
			if (sum >= 1) {
				id = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if (id == -1) {
			see(A);
			see(B);
			see(id);
			see(i, N, st.query(i, N).sum);
			cout << "-1\n";
			return;
		}
		swap(B[i], B[id]);
		if (A[i] < B[i]) {
			cout << "-1\n";
			return;
		}

		if (A[id] < B[id]) {
			st.update(id, 1);
		} else {
			st.update(id, 0);
		}
	}

	FOR(i, 1, N) {
		if (A[i] < B[i]) {
			cout << "-1\n";
			return;
		}
		cout << min(A[i], B[i]) << ' ' << max(A[i], B[i]) << ' ';
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
