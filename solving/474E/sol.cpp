/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 12:00:11 PM IST
(ツ) It is better to travel well than to arrive.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

long long gcd(long long a, long long b) { 
    if(a == 0 && b == 0) return 0;
    return b == 0 ? a : gcd(b, a % b); 
}

const int N = 1e5 + 5, inf = 1e18;

int n, a[N], Q, tree[N << 2];
map<int, vector<int>> pos;

void upd(int tl, int tr, int node, int id, int val) {
	if (tl > tr)
		return;
	if (tl == tr) {
		assert(tl == id);
		tree[node] = a[tl];
		return;
	}

	int mid = (tl + tr) >> 1;

	if (id <= mid) 
		upd(tl, mid, 2 * node, id, val);
	else
		upd(mid + 1, tr, 2 * node + 1, id, val);

	tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
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

	return gcd(left, right);
}

int getGCD(int L, int R) {
	return get(1, n, 1, L, R);
}

int getOccurences(int val, int L, int R) {
	if (pos[val].empty())
		return 0;
	vector<int> &chk = pos[val];

	int left = -1;
	int lo = 0, hi = sz(chk) - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (chk[mid] >= L) {
			left = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	int right = -1;
	lo = 0, hi = sz(chk) - 1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (chk[mid] <= R) {
			right = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	if (left == -1 or left > right)
		return 0;

	assert(left <= right);
	return (right - left + 1);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	FOR(i,1,n) {
		cin >> a[i];
		upd(i, a[i]);
		pos[a[i]].push_back(i);
	}

	cin >> Q;

	while (Q--) {
		int L, R;
		cin >> L >> R;

		int g = getGCD(L, R);
		int ans = (R - L + 1) - getOccurences(g, L, R);

		cout << ans << "\n";
	}
}
