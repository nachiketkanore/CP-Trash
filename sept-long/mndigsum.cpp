/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 September 2021 03:29:37 PM IST
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

pair<int, int> sod(int val, int base) {
	int ret = 0;
	while (val > 0) {
		ret += val % base;
		val /= base;
	}
	return make_pair(ret, base);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, L, R;
		cin >> N >> L >> R;
		pair<int, int> ans = sod(N, R);
		for (int i = L; i <= R && i * i <= N; i++) {
			ans = min(ans, sod(N, i));
		}
		for (int k = 1;; k++) {
			int base = N / k;
			if (L <= base && base <= R)
				ans = min(ans, sod(N, base));
			if (1LL * base * base > 1LL * N)
				continue;
			else
				break;
		}
		cout << ans.second << '\n';
	}
}
