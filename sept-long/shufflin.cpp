/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 September 2021 02:58:43 PM IST
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
		int e1 = 0, e2 = 0;
		int o1 = 0, o2 = 0;
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int u;
			cin >> u;
			e1 += u % 2 == 0;
			e2 += i % 2 == 0;
			o1 += u % 2 == 1;
			o2 += i % 2 == 1;
		}
		cout << min(o1, e2) + min(o2, e1) << '\n';
	}
}

/* o e */
/* 2 1 */
/* 2 1 */
