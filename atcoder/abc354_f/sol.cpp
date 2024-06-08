/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 08 June 2024 04:38:36 PM IST
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
int N, A[MAX_N];

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
		mn = 0;
		mx = 0;
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
} tree;

void coordinate_compress() {
	vector<int> values;
	FOR(i, 1, N) values.push_back(A[i]);
	sort(ALL(values));
	FOR(i, 1, N) A[i] = lower_bound(ALL(values), A[i]) - values.begin() + 1;
}

void solve() {
	FOR(i, 1, N) tree.update(i, 0);

	cin >> N;
	FOR(i, 1, N) cin >> A[i];

	coordinate_compress();

	vector<int> dp_left(N + 1);

	int LIS = 0;

	FOR(i, 1, N) {
		int here = 1 + tree.query(1, A[i] - 1).mx;
		LIS = max(LIS, here);
		tree.update(A[i], max(tree.query(A[i]).mx, here));
		dp_left[i] = here;
		// see(i, dp_left[i]);
	}

	// see(LIS);

	FOR(i, 1, N) tree.update(i, 0);

	vector<int> answers;

	for (int i = N; i >= 1; i--) {
		int right = tree.query(A[i] + 1, N).mx;
		int here = dp_left[i] + right;
		// see(here, right);
		if (here == LIS) {
			answers.push_back(i);
		}
		tree.update(A[i], max(tree.query(A[i]).mx, 1 + right));
	}

	sort(ALL(answers));
	cout << sz(answers) << '\n';
	for (int idx : answers) {
		cout << idx << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	tree.init(MAX_N);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
