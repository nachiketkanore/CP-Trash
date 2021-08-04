/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 August 2021 12:49:18 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 1e6;

int n, x, a[N];
int bit[N];

void upd(int id, int add) {
	while (id < N) {
		bit[id] += add;
		id += id & -id;
	}
}

int pref(int id) {
	int ret = 0;
	while (id > 0) {
		ret += bit[id];
		id -= id & -id;
	}
	return ret;
}

int32_t main() {
	cin >> n >> x;
	FOR (i,1,n) {
		cin >> a[i];
		if (a[i] == x) {
			upd(i, 1);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int L, R, k;
			cin >> L >> R >> k;
			if (pref(R) - pref(L - 1) < k) {
				cout << "-1\n";
				continue;
			}
			int behind = pref(L - 1);
			// smallest id such that pref(id) - behind >= k
			int ans = -1;
			int lo = 1, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				int val = pref(mid) - behind;
				if (val >= k) ans = mid, hi = mid - 1;
				else lo = mid + 1;
			}
			assert(~ans);
			assert(L <= ans && ans <= R);
			cout << ans << '\n';
		} else {
			int id, val;
			cin >> id >> val;
			if (a[id] == x) {
				upd(id, -1);
			}
			a[id] = val;
			if (a[id] == x) {
				upd(id, 1);
			}
		}
	}
}
