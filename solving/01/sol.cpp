/*
Author: Nachiket Kanore
Created: Saturday 31 October 2020 02:56:06 PM IST
(ツ) The secret of joy in work is contained in one word: excellence. To know how to do something well is to enjoy it.
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

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e6 + 5;

int n, q, a[N], tree[N << 2];

void upd(int tl, int tr, int node, int id, int val) {
	if (tl > tr)
		return;
	if (tl == tr) {
		assert(tl == id);
		tree[node] = val;
		return;
	}

	int mid = (tl + tr) >> 1;
	if (id <= mid)
		upd(tl, mid, 2 * node, id, val);
	else
		upd(mid + 1, tr, 2 * node + 1, id, val);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void upd(int id, int val) {
	upd(1, n, 1, id, val);
}

int get(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return 0;
	if (tl == ql && tr == qr)
		return tree[node];
	int mid = (tl + tr) >> 1;
	int left = get(tl, mid, 2 * node, ql, min(mid, qr));
	int right = get(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);
	return left + right;
}

int get(int L, int R) {
	return get(1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	FOR(i, 1, n) cin >> a[i], a[i] %= 2;

	FOR(i, 1, n) upd(i, a[i]);

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int id;
			cin >> id;
			a[id] = (a[id] + 1) % 2;
			upd(id, a[id]);
		} else {
			int k;
			cin >> k;
			int ans = -1;
			int lo = 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				int prefSum = get(1, mid);
				if (prefSum >= k) {
					ans = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			if (1 <= ans && ans <= n && get(1, ans) == k)
				cout << ans << "\n";
			else
				cout << "-1\n";
		}
	}
}
