/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 01:05:16 PM IST
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
	srand(time(0));
	int T = rand() % 10000 + 1;
	cout << T << '\n';
	while (T--) {
		int N = rand() % 1000000000000000 + 1;
		int M = rand() % 1000000000 + 1;
		cout << N << ' ' << M << '\n';
	}
}
