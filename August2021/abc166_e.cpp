/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 05:55:08 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
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
	// j < i
	// i - j = a[i] + a[j]
	// i - a[i] = j + a[j]
	int N, ans = 0;
	cin >> N;
	map<int, int> bmap;
	FOR(i, 1, N) {
		int val;
		cin >> val;
		ans += bmap[i - val];
		bmap[i + val]++;
	}
	cout << ans << '\n';
}
