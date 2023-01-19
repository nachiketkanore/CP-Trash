/*
Author: Nachiket Kanore
Created: Sunday 01 November 2020 01:55:13 PM IST
(ツ) We have two ears and one mouth so that we can listen twice as much as we speak.
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

const int N = 1e5 + 5;

string s;
int n, tree[26][N << 2];

void pull(int which, int node) {
	tree[which][node] = tree[which][2 * node] + tree[which][2 * node + 1];
}

void upd(int which, int tl, int tr, int node, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		tree[which][node] = val;
		return;
	}

	int mid = (tl + tr) >> 1;

	if (id <= mid)
		upd(which, tl, mid, 2 * node, id, val);
	else
		upd(which, mid + 1, tr, 2 * node + 1, id, val);

	pull(which, node);
}

void upd(int which, int id, int val) {
	upd(which, 1, n, 1, id, val);
}

int get(int which, int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return 0;
	if (tl == ql && tr == qr)
		return tree[which][node];
	int mid = (tl + tr) >> 1;

	int left = get(which, tl, mid, 2 * node, ql, min(mid, qr));
	int right = get(which, mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	return (left + right);
}

int getSum(int which, int L, int R) {
	return get(which, 1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = sz(s);
	s = "@" + s;

	FOR(i, 1, n) upd(s[i] - 'a', i, 1);

	int Q;
	cin >> Q;
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			cin >> pos;

			upd(s[pos] - 'a', pos, 0);

			char ch;
			cin >> ch;
			s[pos] = ch;

			upd(s[pos] - 'a', pos, 1);

		} else {
			int L, R, ans = 0;
			cin >> L >> R;

			FOR(ch, 0, 25) ans += getSum(ch, L, R) > 0;

			cout << ans << "\n";
		}
	}
}
