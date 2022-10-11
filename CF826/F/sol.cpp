/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 08:53:51 PM IST
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

const int MX = 2e5 + 5;
int N;
vector<array<int, 3>> lines[MX];

class implicit_segtree {
	public:
	struct node {
		pair<int, int> val;
		node* left;
		node* right;
		node(pair<int, int> _val = make_pair(0, N + 1), node* _left = NULL, node* _right = NULL) {
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
		return make_pair(0, N + 1);
	}
	void update(long long l, long long r, pnode& tree, long long idx, int value, int pos) {
		if (!tree) {
			tree = new node();
		}
		if (l == r) {
			tree->val = max(tree->val, make_pair(value, pos));
			return;
		}
		long long mid = (l + r) >> 1;
		if (idx <= mid) {
			update(l, mid, tree->left, idx, value, pos);
		} else {
			update(mid + 1, r, tree->right, idx, value, pos);
		}
		tree->val = max(val(tree->left), val(tree->right));
	}
	pair<int, int> query(long long l, long long r, pnode tree, long long ql, long long qr) {
		if (!tree || l > qr || r < ql || ql > qr) {
			return make_pair(0, N + 1);
		}
		if (l >= ql && r <= qr) {
			return val(tree);
		}
		long long mid = (l + r) >> 1;
		return max(query(l, mid, tree->left, ql, qr), query(mid + 1, r, tree->right, ql, qr));
	}
	pnode root = NULL;
};

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		lines[i].clear();
	}
	implicit_segtree segleft, segright;
	map<int, vector<int>> left, right;
	FOR(i, 1, N) {
		int l, r, c;
		cin >> l >> r >> c;
		lines[c].push_back({ l, r, i });
		left[r].push_back(l);
		right[l].push_back(r);
	}
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
