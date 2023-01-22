/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 07:15:47 PM IST
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

const int N = 2e5 + 5;
vector<int> pos[N];
int n, M, k;

int32_t main() {
	cin >> n >> M >> k;
	FOR(i, 1, n) {
		int u;
		cin >> u;
		pos[u].push_back(i);
	}

	auto possible = [&](int len) {
		FOR(i, 1, M) {
			if (sz(pos[i]) < len)
				continue;
			for (int id = 0; id < sz(pos[i]); id++) {
				int j = id + len - 1;
				if (j >= sz(pos[i]))
					continue;
				int remove = (pos[i][j] - pos[i][id] + 1) - len;
				if (remove <= k) {
					return true;
				}
			}
		}
		return false;
	};

	int ans = -1;
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (possible(mid))
			ans = mid, lo = mid + 1;
		else
			hi = mid - 1;
	}
	assert(~ans);
	cout << ans;
}
