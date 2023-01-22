/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 06:01:37 PM IST
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

#define ll int64_t
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

const int _ = 2e5 + 5;
ll N, A[_], B[_];

class segtree {
	public:
	int N;
	vector<ll> st;
	segtree(int N) : N(N) {
		st = vector<ll>(N << 2);
		build(1, 1, N);
	}
	inline void build(int u, int L, int R) {
		if (L == R)
			st[u] = B[L];
		else {
			int mid = (L + R) / 2;
			build(2 * u, L, mid);
			build(2 * u + 1, mid + 1, R);
			st[u] = __gcd(st[2 * u], st[2 * u + 1]);
		}
	}
	inline ll qry(int u, int tl, int tr, int ql, int qr) const {
		if (tl > tr || ql > qr || tr < ql || qr < tl)
			return 0;
		if (tl == ql && tr == qr)
			return st[u];
		int mid = (tl + tr) / 2;
		return __gcd(qry(2 * u, tl, mid, ql, min(mid, qr)), qry(2 * u + 1, mid + 1, tr, max(mid + 1, ql), qr));
	}
	inline ll query(int L, int R) const {
		return qry(1, 1, N, L, R);
	}
};

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 1, N) {
			cin >> A[i];
		}
		FOR(i, 1, N - 1) {
			B[i] = abs(A[i + 1] - A[i]);
		}
		segtree tree(N);
		int ans = 1;
		FOR(L, 1, N) {
			int lo = L, hi = N - 1;
			int R = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (tree.query(L, mid) > 1) {
					R = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (~R) {
				assert(R < N);
				cmax(ans, (R + 1) - L + 1);
			}
			if (ans > N - L)
				break;
		}
		cout << ans << '\n';
	}
}
