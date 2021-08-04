/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 05:50:55 PM IST
(ツ) Keep true to the dreams of thy youth.
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

const int N = 2e5 + 5, inf = 1e18;

int n, t, c;
int tree[N << 2];

void upd(int tl, int tr, int node, int id, int val) {
	if (tl > tr) return;
	if (tl == tr) {
		tree[node] = max(tree[node], val);
		return;
	}
	int mid = (tl + tr) >> 1;
	if (id <= mid)
		upd(tl, mid, 2 * node, id, val);
	else 
		upd(mid + 1, tr, 2 * node + 1, id, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr) return -inf;
	if (tl == ql && tr == qr)
		return tree[node];
	int mid = (tl + tr) >> 1;
	int left = query(tl, mid, 2 * node, ql, min(qr, mid));
	int right = query(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);
	return max(left, right);
}

int getMax(int L, int R) {
	return query(1, n, 1, L, R);
}

void put(int id, int val) {
	upd(1, n, 1, id, val);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> t >> c;

	FOR(i,1,n) {
		int val;
		cin >> val;
		put(i, val);
	}

	int ans = 0;

	FOR(i,1,n) if (i + c - 1 <= n) {
		ans += getMax(i, i + c - 1) <= t;
	}
	cout << ans;
}
// Overkill