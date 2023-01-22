/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 04:10:18 PM IST
(ツ) The grand essentials of happiness are: something to do, something to love, and something to hope for.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 2e9;

int n, a[N], tree[N << 2];

void put(int tl, int tr, int node, int id, int val) {
	if (tl > tr)
		return;

	if (tl == tr) {
		tree[node] = val;
		return;
	}

	int mid = (tl + tr) >> 1;
	if (id <= mid) {
		put(tl, mid, 2 * node, id, val);
	} else {
		put(mid + 1, tr, 2 * node + 1, id, val);
	}

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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n) {
		cin >> a[i];
		upd(i, a[i]);
	}

	set<int> available;

	FOR(i, 1, n) {
		available.insert(i);
	}

	while (!available.empty()) {

		vector<int> taken;
		int currId = *available.begin();

		while (1) {
			assert(~a[currId]);
			available.erase(available.find(currId));
			taken.push_back(currId);
			int from = currId + 1;
			int next = -1;

			int lo = from, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (getMax(from, mid) > a[currId]) {
					next = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			if (~next) {
				assert(available.count(next));
				currId = next;
			} else {
				break;
			}
		}

		assert(sz(taken));
		for (int id : taken)
			cout << a[id] << ' ';
		cout << "\n";

		for (int id : taken) {
			upd(id, -1);
			a[id] = -1;
		}
	}
}
