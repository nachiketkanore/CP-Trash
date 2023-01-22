/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 01:15:43 PM IST
(ツ) With courage you will dare to take risks, have the strength to be compassionate, and the wisdom to be humble. Courage is the foundation of integrity.
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
using pii = pair<int, int>;

const int N = 1e5 + 5, inf = 2e9;

int n, m, a[N], dpLeft[N], dpRight[N];
pii tree[N << 2];

void upd(int tl, int tr, int node, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		tree[node] = { val, id };
	} else {
		int mid = (tl + tr) >> 1;

		if (id <= mid)
			upd(tl, mid, 2 * node, id, val);
		else
			upd(mid + 1, tr, 2 * node + 1, id, val);

		tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	}
}

void put(int id, int val) {
	upd(1, n, 1, id, val);
}

pii getMax(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return { -inf, -inf };
	if (tl == ql && tr == qr)
		return tree[node];

	int mid = (tl + tr) >> 1;

	pii left = getMax(tl, mid, 2 * node, ql, min(mid, qr));
	pii right = getMax(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	return max(left, right);
}

int getMaxId(int L, int R) {
	assert(L <= R);
	pii ret = getMax(1, n, 1, L, R);
	int ans = ret.second;
	assert(L <= ans && ans <= R);
	return ans;
}

int goLeft(int id) {
	if (id == 0)
		return 0;
	int& ans = dpLeft[id];
	if (~ans)
		return ans;
	ans = 1;

	if (a[id - 1] <= a[id]) {
		ans = ans + goLeft(id - 1);
	}
	return ans;
}

int goRight(int id) {
	if (id == n + 1)
		return 0;
	int& ans = dpRight[id];
	if (~ans)
		return ans;
	ans = 1;

	if (a[id + 1] <= a[id]) {
		ans = ans + goRight(id + 1);
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	memset(dpLeft, -1, sizeof(dpLeft));
	memset(dpRight, -1, sizeof(dpRight));
	a[0] = inf, a[n + 1] = inf;
	FOR(i, 1, n) {
		cin >> a[i];
		put(i, a[i]);
	}

	FOR(i, 1, n) {
		goLeft(i);
		goRight(i);
	}

	FOR(i, 1, m) {
		int L, R;
		cin >> L >> R;
		int maxId = getMaxId(L, R);
		int wantLeft = maxId - L + 1, wantRight = R - maxId + 1;

		if (wantLeft <= goLeft(maxId) && wantRight <= goRight(maxId))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
