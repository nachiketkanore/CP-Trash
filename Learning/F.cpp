/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 August 2021 08:23:20 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 5e5 + 5;
int n, A[N];
int st[N << 2];

void upd(int u, int tl, int tr, int id, int val) {
	if (tl == tr) {
		assert(tl == id);
		st[u] = val;
	} else {
		int mid = (tl + tr) / 2;
		if (id <= mid)
			upd(2 * u, tl, mid, id, val);
		else
			upd(2 * u + 1, mid + 1, tr, id, val);
		st[u] = __gcd(st[2 * u], st[2 * u + 1]);
	}
}

void update(int id, int val) {
	upd(1, 1, 2 * n, id, val);
}

int qry(int u, int tl, int tr, int ql, int qr) {
	if (tl > tr || ql > qr || qr < tl || tr < ql)
		return 0;
	if (tl == ql && tr == qr)
		return st[u];
	int mid = (tl + tr) / 2;
	int left = qry(2 * u, tl, mid, ql, min(mid, qr));
	int right = qry(2 * u + 1, mid + 1, tr, max(mid + 1, ql), qr);
	return __gcd(left, right);
}

int query(int ql, int qr) {
	return qry(1, 1, 2 * n, ql, qr);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 1, n << 1) {
			if (i <= n)
				cin >> A[i];
			else
				A[i] = A[i - n];
			update(i, A[i]);
		}
		auto validate = [&](int steps) {
			int which = -1;
			FOR(i, 1, n) {
				int add = query(i, i + steps);
				if (which == -1)
					which = add;
				else if (which ^ add)
					return false;
			}
			return true;
		};

		int lo = 0, hi = n;
		int ans = -1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;

			if (validate(mid))
				ans = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}

		assert(~ans);
		cout << ans << '\n';
	}
}
