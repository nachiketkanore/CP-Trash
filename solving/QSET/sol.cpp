/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 10:54:40 PM IST
(ツ) The amount of happiness that you have depends on the amount of freedom you have in your heart.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 2;

int n, Q;
int a[N];

struct node {
	static const int inf = 1e18;
	int sum;
	vector<int> pref;

	node(int val, bool good) {
		sum = 0;
		pref = vector<int>(3, 0);
		if (good) {
			sum = val % 3;
			pref[val % 3] = 1;
		}
	}

	node() {
		sum = 0;
		pref = vector<int>(3, 0);
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
		ret.sum = 0;
		ret.pref = vector<int>(3, 0);
		ret.sum = (left.sum + right.sum) % 3;
		for (int i = 0; i < 3; i++) {
			ret.pref[i] += left.pref[i];
			int new_mod = (left.sum + i) % 3;
			ret.pref[new_mod] += right.pref[i];
		}
	}

	void build(int u, int L, int R) {
		if (L == R) {
			// Leaf value
			st[u] = node(a[L], true);
			return;
		}
		int M = (L + R) / 2;
		build(u * 2, L, M);
		build(u * 2 + 1, M + 1, R);
		merge(st[u], st[u * 2], st[u * 2 + 1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if (i == L && R == j)
			return st[u];
		int M = (L + R) / 2;
		if (i > M)
			return Query(u * 2 + 1, M + 1, R, i, j);
		if (j <= M)
			return Query(u * 2, L, M, i, j);
		node left = Query(u * 2, L, M, i, M);
		node right = Query(u * 2 + 1, M + 1, R, M + 1, j);
		node ret(0, false);
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
			st[u] = node(val, true);
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

int get(node ans) {
	int ret = 0;
	int c0 = ans.pref[0] + 1;
	ret += c0 * (c0 - 1) / 2;
	int c1 = ans.pref[1];
	ret += c1 * (c1 - 1) / 2;
	int c2 = ans.pref[2];
	ret += c2 * (c2 - 1) / 2;
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> Q;
	FOR(i, 1, n) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}

	tree.init(n);

	while (Q--) {
		int T;
		cin >> T;
		if (T == 1) {
			int id, val;
			cin >> id >> val;
			tree.update(id, val);
		} else {
			int L, R;
			cin >> L >> R;
			cout << get(tree.query(L, R)) << "\n";
		}
	}
}
