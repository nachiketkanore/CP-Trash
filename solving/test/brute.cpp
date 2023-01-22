/*
Author: Nachiket Kanore
Created: Monday 04 January 2021 08:39:31 PM IST
(ツ) Spring is a time for rebirth and the fulfilment of new life.
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

const int N = 2e5 + 5, inf = 1e10;

int h[N], w[N];

class implicit_segtree {
	public:
	struct node {
		pair<int, int> val;
		node* left;
		node* right;
		node(pair<int, int> _val = make_pair(inf, inf + 1), node* _left = NULL, node* _right = NULL) {
			val = _val;
			left = _left;
			right = _right;
		}
	};
	typedef node* pnode;
	pair<int, int> val(pnode tree) {
		if (tree) {
			return tree->val;
		}
		return make_pair(inf, inf + 1);
	}
	void update(long long l, long long r, pnode& tree, long long idx, int value, int pos) {
		if (!tree) {
			tree = new node();
		}
		if (l == r) {
			tree->val = min(tree->val, make_pair(value, pos));
			return;
		}
		long long mid = (l + r) >> 1;
		if (idx <= mid) {
			update(l, mid, tree->left, idx, value, pos);
		} else {
			update(mid + 1, r, tree->right, idx, value, pos);
		}
		tree->val = min(val(tree->left), val(tree->right));
	}
	pair<int, int> query(long long l, long long r, pnode tree, long long ql, long long qr) {
		if (!tree || l > qr || r < ql || ql > qr) {
			return make_pair(inf, inf + 1);
		}
		if (l >= ql && r <= qr) {
			return val(tree);
		}
		long long mid = (l + r) >> 1;
		return min(query(l, mid, tree->left, ql, qr), query(mid + 1, r, tree->right, ql, qr));
	}
	pnode root = NULL;
	~implicit_segtree() {
		if (root)
			delete (root);
	}
};

void solve() {
	implicit_segtree one, two;

	int n;
	cin >> n;
	FOR(i, 1, n) cin >> h[i] >> w[i];

	FOR(i, 1, n) {
		one.update(1, inf, one.root, h[i], w[i], i);
		two.update(1, inf, two.root, w[i], h[i], i);
	}

	FOR(i, 1, n) {
		pair<int, int> best1 = one.query(1, inf, one.root, 1, h[i] - 1);
		pair<int, int> best2 = two.query(1, inf, two.root, 1, h[i] - 1);

		if (best1.first < w[i]) {
			assert(best1.second <= n);
			cout << best1.second << ' ';
		} else if (best2.first < w[i]) {
			assert(best2.second <= n);
			cout << best2.second << ' ';
		} else
			cout << -1 << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
