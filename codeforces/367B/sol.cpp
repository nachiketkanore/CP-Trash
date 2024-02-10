/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 10 February 2024 11:04:55 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

class node {
	public:
	static const int inf = 1e9;
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

const int MAX = 2e5 + 5;
int N, M, P;
vector<pair<int, int>> groups[MAX];

void coordinate_compress(vector<int>& A, vector<int>& B) {
	vector<int> values;
	for (int a : A)
		values.push_back(a);
	for (int b : B)
		values.push_back(b);
	sort(ALL(values));
	for (int& a : A)
		a = lower_bound(ALL(values), a) - values.begin() + 1;
	for (int& b : B)
		b = lower_bound(ALL(values), b) - values.begin() + 1;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> P;
	vector<int> A(N), B(M);
	for (auto& a : A)
		cin >> a;
	for (auto& b : B)
		cin >> b;
	coordinate_compress(A, B);

	FOR(i, 1, N) groups[i % P].push_back({ A[i - 1], i });

	segtree freq;
	freq.init(2 * N + 2);

	for (int b : B) {
		freq.update(b, freq.query(b).mn + 1);
	}

	auto check = [&]() {
		auto result = freq.query(1, 2 * N + 2);
		return result.mn == 0 && result.mx == 0;
	};

	vector<int> positions;

	F0R(mod, P) {
		const auto& g = groups[mod];
		if (sz(g) < M)
			continue;
		const int len = sz(g);

		F0R(id, M) {
			freq.update(g[id].first, freq.query(g[id].first).mn - 1);
		}
		if (check())
			positions.push_back(g[0].second);

		int rem_id = 0;
		for (int id = M; id < len; id++, rem_id++) {
			freq.update(g[rem_id].first, freq.query(g[rem_id].first).mn + 1);
			freq.update(g[id].first, freq.query(g[id].first).mn - 1);
			if (check())
				positions.push_back(g[rem_id + 1].second);
		}
		while (rem_id < len) {
			freq.update(g[rem_id].first, freq.query(g[rem_id].first).mn + 1);
			rem_id++;
		}
	}

	sort(ALL(positions));
	cout << sz(positions) << '\n';
	for (int pos : positions) {
		cout << pos << ' ';
	}

	return 0;
}
