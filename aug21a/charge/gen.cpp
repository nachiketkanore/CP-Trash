/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 August 2021 07:36:25 PM IST
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
	int T = 1;
	cout << T << '\n';
	while (T--) {
		int N = rand() % 10 + 1;
		cout << N << '\n';
		FOR(i, 1, N) cout << rand() % 10 + 1 << ' ';
		cout << '\n';
		FOR(i, 1, N) cout << rand() % 10 + 1 << ' ';
		cout << '\n';
	}
}
