// For heavy recursions
// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2")

#include "bits/stdc++.h"
using namespace std;

int w;

void test() {
	return -1;
}

struct segtree {
	struct data {
		int sum, pref, suff, ans;
	};

	int N;
	vector<data> t;

	segtree(int n) {
		N = n;
		t = vector<data>(N << 2);
	}

	data combine(data l, data r) {
		data res;
		res.sum = l.sum + r.sum;
		res.pref = max(l.pref, l.sum + r.pref);
		res.suff = max(r.suff, r.sum + l.suff);
		res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
		return res;
	}

	data make_data(int val) {
		data res;
		res.sum = val;
		res.pref = res.suff = res.ans = max(0, val);
		return res;
	}

	// void build(int a[], int v, int tl, int tr) {
	//     if (tl == tr) {
	//         t[v] = make_data(a[tl]);
	//     } else {
	//         int tm = (tl + tr) / 2;
	//         build(a, v*2, tl, tm);
	//         build(a, v*2+1, tm+1, tr);
	//         t[v] = combine(t[v*2], t[v*2+1]);
	//     }
	// }

	void update(int v, int tl, int tr, int pos, int new_val) {
		if (tl == tr) {
			t[v] = make_data(new_val);
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				update(v * 2, tl, tm, pos, new_val);
			else
				update(v * 2 + 1, tm + 1, tr, pos, new_val);
			t[v] = combine(t[v * 2], t[v * 2 + 1]);
		}
	}

	data query(int v, int tl, int tr, int l, int r) {
		if (l > r)
			return make_data(0);
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) / 2;
		return combine(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
};

int main() {
	int n;
	cin >> n;
	segtree one(n), two(n);
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (i & 1) {
			one.update(1, 1, n, i, u);
			two.update(1, 1, n, i, -u);
		} else {
			one.update(1, 1, n, i, -u);
			two.update(1, 1, n, i, u);
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int id, val;
			cin >> id >> val;
			if (id & 1) {
				one.update(1, 1, n, id, val);
				two.update(1, 1, n, id, -val);
			} else {
				one.update(1, 1, n, id, -val);
				two.update(1, 1, n, id, val);
			}
		} else {
			int L, R;
			cin >> L >> R;
			if (L & 1)
				cout << one.query(1, 1, n, L, R).ans << '\n';
			else
				cout << two.query(1, 1, n, L, R).ans << '\n';
		}
	}
}
