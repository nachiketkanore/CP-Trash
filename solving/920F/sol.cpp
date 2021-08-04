/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 10:21:54 PM IST
(ツ) If you're in a bad situation, don't worry it'll change. If you're in a good situation, don't worry it'll change.
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

const int M = 3e5 + 5;
const int N = 1e6 + 5, inf = 1e18;

int n, Q, a[M], divs[N + 5];

struct treeNode {
	int sum = 0;
	int mx = 0;
} tree[M << 2];

void pre() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			divs[j]++;
		}
	}
}

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


void upd(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr || tree[node].mx <= 2) 
		return;

	if (tl == tr) {
		assert(tree[node].mx == tree[node].sum);
		tree[node].sum = tree[node].mx = divs[tree[node].sum];
		return;
	}

	int mid = (tl + tr) >> 1;

	upd(tl, mid, 2 * node, ql, min(mid, qr));
	upd(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	pull(node); 
}

void REPLACE(int L, int R) {
	upd(1, n, 1, L, R);
}

int get(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr) 
		return 0;

	if (tl == ql && tr == qr)
		return tree[node].sum;

	int mid = (tl + tr) >> 1;

	int left = get(tl, mid, 2 * node, ql, min(mid, qr));
	int right = get(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	return (left + right);
}

int SUM(int L, int R) {
	return get(1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	pre();

	cin >> n >> Q;

	FOR(i, 1, n) {
		cin >> a[i];
	}

	build(1, n, 1);

	while (Q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int L, R;
			cin >> L >> R;
			REPLACE(L, R);
		} else {
			int L, R;
			cin >> L >> R;
			cout << SUM(L, R) << "\n";
		}
	}
}
