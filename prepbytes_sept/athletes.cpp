/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 03:10:46 PM IST
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

const int _ = 1e5 + 5;
struct DSU {
	int connected;
	int par[_], sz[_];

	void init(int n) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		connected = n;
	}

	int getPar(int k) {
		while (k != par[k]) {
			par[k] = par[par[k]];
			k = par[k];
		}
		return k;
	}

	int getSize(int k) {
		return sz[getPar(k)];
	}

	bool same(int u, int v) {
		return (getPar(u) == getPar(v));
	}

	bool unite(int u, int v) {
		int par1 = getPar(u), par2 = getPar(v);

		if (par1 == par2)
			return false;

		connected--;

		if (sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
		return true;
	}
} dsu;

int N, M;
int A[_];

int32_t main() {
	cin >> N >> M;
	dsu.init(N);
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		u++, v++;
		dsu.unite(u, v);
	}
	int ans = 0, prev = 0;
	FOR(i, 1, N) {
		if (dsu.getPar(i) == i) {
			int curr = dsu.getSize(i);
			ans += prev * curr;
			prev += curr;
		}
	}
	cout << ans << '\n';
}
