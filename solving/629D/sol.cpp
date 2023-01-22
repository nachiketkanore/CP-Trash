/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 03:24:11 PM IST
(ツ) You may be deceived if you trust too much, but you will live in torment if you don't trust enough.
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
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const double PI = (double)acos(-1);
const int N = 1e5 + 5, inf = 1e18;

int n, vol[N], tree[N << 2];
int new_vol[N];

void put(int tl, int tr, int node, int id, int val) {
	if (tl > tr)
		return;
	if (tl == tr) {
		tree[node] = max(tree[node], val);
		return;
	}

	int mid = (tl + tr) >> 1;
	if (id <= mid)
		put(tl, mid, 2 * node, id, val);
	else
		put(mid + 1, tr, 2 * node + 1, id, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int get(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return -inf;
	if (tl == ql && tr == qr)
		return tree[node];
	int mid = (tl + tr) >> 1;
	int left = get(tl, mid, 2 * node, ql, min(qr, mid));
	int right = get(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);
	return max(left, right);
}

void upd(int id, int val) {
	put(1, n, 1, id, val);
}

int getMax(int L, int R) {
	return get(1, n, 1, L, R);
}

void compress() {
	vector<int> vals;

	FOR(i, 1, n) {
		vals.push_back(vol[i]);
	}

	sort(vals.begin(), vals.end());

	FOR(i, 1, n) {
		new_vol[i] = (lower_bound(vals.begin(), vals.end(), vol[i]) - vals.begin() + 2);
		assert(new_vol[i] >= 1);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n) {
		int r, h;
		cin >> r >> h;
		vol[i] = r * r * h;
	}

	compress();

	int ans = 0;

	FOR(i, 1, n) {
		int id = new_vol[i];
		int currBest = vol[i] + getMax(1, id - 1);
		upd(id, currBest);
		ans = max(ans, currBest);
	}

	double ret = 1.0 * PI * ans;
	printf("%.10f\n", ret);
}
