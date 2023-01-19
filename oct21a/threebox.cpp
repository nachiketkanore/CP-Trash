/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 06 October 2021 04:02:45 PM IST
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
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		if (A + B + C <= D) {
			cout << "1\n";
		} else if (A + B <= D || A + C <= D || B + C <= D) {
			cout << "2\n";
		} else {
			cout << "3\n";
		}
	}
}
