/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 10:30:26 AM IST
(ツ) The most beautiful things in the world cannot be seen or even touched. They must be felt with the heart.
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

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e9;

int n, m, k, tree[6][N << 2];

void upd(int tl, int tr, int node, int id, int val, int which) {
	if (tl > tr) return;
	if (tl == tr) {
		tree[which][node] = max(tree[which][node], val);
		return;
	}
	int mid = (tl + tr) >> 1;
	if (id <= mid)
		upd(tl, mid, 2 * node, id, val, which);
	else 
		upd(mid + 1, tr, 2 * node + 1, id, val, which);
	tree[which][node] = max(tree[which][2 * node], tree[which][2 * node + 1]);
}

int query(int tl, int tr, int node, int ql, int qr, int which) {
	if (tl > tr || ql > qr) return -inf;
	if (tl == ql && tr == qr) {
		return tree[which][node];
	}
	int mid = (tl + tr) >> 1;
	int left = query(tl, mid, 2 * node, ql, min(qr, mid), which);
	int right = query(mid + 1, tr, 2 * node + 1, max(ql, mid + 1), qr, which);
	return max(left, right);
}

void put(int which, int id, int val) {
	upd(1, n, 1, id, val, which);
}

int getMax(int which, int L, int R) {
	return query(1, n, 1, L, R, which);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	FOR(i,1,n) {
		FOR(j,1,m) {
			int val;
			cin >> val;
			put(j, i, val);
		}
	}

	int maxLen = 0;
	vector<int> ret(m, 0);

	FOR(i,1,n) {
		int lo = i, hi = n;
		int right = -1;

		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int costReq = 0;
			FOR(j,1,m) {
				costReq += getMax(j, i, mid);
			}
			if (costReq <= k) {
				right = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		if (~right) {
			int tot = right - i + 1;
			assert(tot > 0);
			if (tot > maxLen) {
				maxLen = tot;
				FOR(j,1,m) {
					ret[j - 1] = getMax(j, i, right);
				}
			}
		}
	}

	assert(sz(ret) == m);
	for (int x : ret) cout << x << ' ';
}
