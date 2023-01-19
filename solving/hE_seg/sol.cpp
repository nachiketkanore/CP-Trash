/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 02:59:59 PM IST
(ツ) Example has more followers than reason.
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

const int N = 1e5 + 2, mod = 1e9 + 7;

int n, q;
int a[N];

int tree[11][N << 2];

void upd(int which, int u, int tl, int tr, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		tree[which][u] = val;
		return;
	}

	int mid = (tl + tr) / 2;
	if (id <= mid)
		upd(which, 2 * u, tl, mid, id, val);
	else
		upd(which, 2 * u + 1, mid + 1, tr, id, val);
	tree[which][u] = tree[which][2 * u] + tree[which][2 * u + 1];
}

void update(int which, int id, int val) {
	upd(which, 1, 1, n, id, val);
}

int qry(int which, int u, int tl, int tr, int ql, int qr) {
	if (ql > qr || tl > tr)
		return 0;
	if (ql == tl && qr == tr)
		return tree[which][u];
	int mid = (tl + tr) / 2;
	return qry(which, 2 * u, tl, mid, ql, min(qr, mid)) + qry(which, 2 * u + 1, mid + 1, tr, max(mid + 1, ql), qr);
}

int getSum(int which, int L, int R) {
	return qry(which, 1, 1, n, L, R);
}

int distinct_digits(int val) {
	int mask = 0;
	while (val) {
		mask |= 1 << (val % 10);
		val /= 10;
	}
	return __builtin_popcountll(mask);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		update(distinct_digits(a[i]), i, 1);
	}

	cin >> q;
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 0) {
			int id, val;
			cin >> id >> val;
			update(distinct_digits(a[id]), id, 0);
			a[id] += val;
			update(distinct_digits(a[id]), id, 1);
		} else if (ty == 1) {
			int id, val;
			cin >> id >> val;
			update(distinct_digits(a[id]), id, 0);
			a[id] = val;
			update(distinct_digits(a[id]), id, 1);
		} else {
			int L, R, C;
			cin >> L >> R >> C;
			cout << getSum(C, L, R) << "\n";
		}
	}
}