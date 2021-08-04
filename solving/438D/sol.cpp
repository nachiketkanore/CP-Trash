/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 07:18:19 PM IST
(ツ) If you would take, you must first give, this is the beginning of intelligence.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

struct treeNode {
	int sum = 0;
	int mx = 0;
} tree[N << 2];

int n, Q, a[N];

void pull(int node) {
	tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
	tree[node].mx = max(tree[2 * node].mx, tree[2 * node + 1].mx);
}

void build(int tl, int tr, int node) {
	if (tl == tr) {
		tree[node].sum = a[tl];
		tree[node].mx = a[tl];
		return;
	}
	int mid = (tl + tr) >> 1;
	build(tl, mid, 2 * node);
	build(mid + 1, tr, 2 * node + 1);
	pull(node);
}

int getSum(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return 0;
	if (ql == tl && qr == tr)
		return tree[node].sum;

	int mid = (tl + tr) >> 1;

	int left = getSum(tl, mid, 2 * node, ql, min(mid, qr));
	int right = getSum(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	return (left + right);
}


int getSum(int L, int R) {
	return getSum(1, n, 1, L, R);
}

void applyMod(int tl, int tr, int node, int ql, int qr, int mod) {
	if (tl > tr || ql > qr || tree[node].mx < mod)
		return;
	if (tl == tr) {
		tree[node].mx %= mod;
		tree[node].sum %= mod;
		return;
	}

	int mid = (tl + tr) >> 1;

	applyMod(tl, mid, 2 * node, ql, min(mid, qr), mod);
	applyMod(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr, mod);
	pull(node);
}

void applyMod(int L, int R, int mod) {
	applyMod(1, n, 1, L, R, mod);
}

void upd(int tl, int tr, int node, int id, int val) {
	if (tl == tr) {
		tree[node].sum = val;
		tree[node].mx = val;
		return;
	}

	int mid = (tl + tr) >> 1;

	if (id <= mid) {
		upd(tl, mid, 2 * node, id, val);
	} else {
		upd(mid + 1, tr, 2 * node + 1, id, val);
	}

	pull(node);
}

void pointUpdate(int id, int val) {
	upd(1, n, 1, id, val);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;

	FOR(i,1,n) {
		cin >> a[i];
	}

	build(1, n, 1);

	while (Q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int L, R;
			cin >> L >> R;
			cout << getSum(L, R) << "\n";
		} else if (type == 2) {
			int L, R, mod;
			cin >> L >> R >> mod;
			applyMod(L, R, mod);
		} else {
			int id, val;
			cin >> id >> val;
			pointUpdate(id, val);
		}
	}
}
