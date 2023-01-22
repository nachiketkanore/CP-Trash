/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 01:10:11 PM IST
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
		int N, D, ans = -1;
		cin >> N >> D;
		for (int i = N;; i++) {
			bool ok = true;
			int val = i;
			while (val) {
				ok &= (val % 10) != D;
				val /= 10;
			}
			if (ok) {
				ans = i;
				break;
			}
		}
		assert(~ans);
		cout << (ans - N) << '\n';
	}
}
