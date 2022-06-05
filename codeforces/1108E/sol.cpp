/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 June 2022 11:10:12 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast32_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 1e5 + 5;
int A[_];

class node {
	public:
	static const int inf = 1e8;
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
			st[u] = node(A[L], A[L], A[L]);
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	FOR(i, 1, N) cin >> A[i];

	vector<array<int, 3>> QL(M);
	vector<array<int, 3>> QR(M);
	F0R(i, M) {
		cin >> QL[i][0] >> QL[i][1];
		QL[i][2] = i + 1;
		QR[i] = QL[i];
		swap(QR[i][0], QR[i][1]);
	}
	sort(ALL(QL));
	sort(ALL(QR));

	segtree st;
	st.init(N);

	int ans = *max_element(A + 1, A + N + 1) - *min_element(A + 1, A + N + 1);
	vector<int> queries;

	set<array<int, 2>> remove_queries;
	// [0] for right endpoint
	// [1] for left endpoint

	FOR(i, 1, N) {
		vector<int> taken;
		int left = -1, right = -1;
		F0R(j, M) {
			const int L = QL[j][0], R = QL[j][1];
			if (L > i) {
				left = j;
				break;
			}
		}
		F0R(j, M) {
			const int L = QR[j][1], R = QR[j][0];
			if (R < i) {
				right = j;
			}
		}

		remove_queries.insert({ left, right });
	}

	vector<array<int, 2>> chk(ALL(remove_queries));

	for (const auto it : chk) {
		int left = it[0], right = it[1];
		vector<int> taken;
		if (left >= 0 && left < M) {
			for (int id = left; id < M; id++) {
				auto [L, R, idx] = QL[id];
				st.update(L, R, -1);
				taken.push_back(idx);
			}
		}
		if (right >= 0 && right < M) {
			assert(left < M);
			for (int id = 0; id <= right; id++) {
				auto [R, L, idx] = QR[id];
				st.update(L, R, -1);
				taken.push_back(idx);
			}
		}

		node get = st.query(1, N);
		if (get.mx - get.mn > ans) {
			ans = get.mx - get.mn;
			queries = taken;
		}

		if (left >= 0 && left < M) {
			for (int id = left; id < M; id++) {
				auto [L, R, idx] = QL[id];
				st.update(L, R, +1);
				taken.push_back(idx);
			}
		}
		if (right >= 0 && right < M) {
			for (int id = 0; id <= right; id++) {
				auto [R, L, idx] = QR[id];
				st.update(L, R, +1);
				taken.push_back(idx);
			}
		}
	}

	cout << ans << '\n';
	cout << sz(queries) << '\n';
	for (int q : queries)
		cout << q << ' ';

	return 0;
}
