/*
Author: Nachiket Kanore
Created: Saturday 31 October 2020 12:55:55 PM IST
(ツ) Arrogance and rudeness are training wheels on the bicycle of life for weak people who cannot keep their balance without them.
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

const int N = 1e5 + 5, inf = (1LL << 40) - 1;

int n, m, l[N], r[N], want[N], ans[N], cnt[N], tree[N << 2];

void upd(int tl, int tr, int node, int id, int val) {
	if (tl > tr) return;
	if (tl == tr) {
		assert(tl == id);
		tree[node] = val;
	} else {
		int mid = (tl + tr) >> 1;
		if (id <= mid)
			upd(tl, mid, 2 * node, id, val);
		else
			upd(mid + 1, tr, 2 * node + 1, id, val);

		tree[node] = tree[2 * node] & tree[2 * node + 1];
	}
}

void upd(int id, int val) {
	upd(1, n, 1, id, val);
}

int get(int tl, int tr, int node, int ql, int qr) {
	if (tl > tr || ql > qr)
		return inf;
	if (tl == ql && tr == qr)
		return tree[node];

	int mid = (tl + tr) >> 1;

	int left = get(tl, mid, 2 * node, ql, min(mid, qr));
	int right = get(mid + 1, tr, 2 * node + 1, max(mid + 1, ql), qr);

	return left & right;
}

int getAND(int L, int R) {
	return get(1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	FOR (i,1,m) {
		cin >> l[i] >> r[i] >> want[i];
	}

	FOR (bit,0,30) {
		FOR (i,1,n+2) cnt[i] = 0;
		
		FOR (i,1,m) {
			if (want[i] >> bit & 1) {
				cnt[l[i]]++;
				cnt[r[i] + 1]--;
			}
		}

		FOR (i,1,n) {
			cnt[i] += cnt[i - 1];
			if (cnt[i] > 0)
				ans[i] |= 1 << bit;
		}
	}

	FOR (i,1,n) upd(i, ans[i]);

	FOR (i,1,m) {
		if (getAND(l[i], r[i]) != want[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	FOR (i,1,n) cout << ans[i] << " \n"[i == n];
}
