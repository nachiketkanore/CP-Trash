/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 02:20:04 PM IST
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k, m, p, q;
		cin >> n >> k >> m >> p >> q;

		auto compute = [&](int upto) {
			int lo = 1, hi = 1e18;
			int ans = 0;

			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				__int128 term = __int128(k) + (mid - 1) * __int128(m);
				if (term <= __int128(upto))
					ans = mid, lo = mid + 1;
				else
					hi = mid - 1;
			}

			return ans;
		};

		int dont_take = compute(q) - compute(p - 1);
		int answer = compute(n) - dont_take;
		cout << answer << '\n';
	}
}
