/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 12:10:45 PM IST
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
	int n;
	cin >> n;
	vector<int> A(n);
	F0R(i, n) cin >> A[i];
	F0R(i, n) {
		int b;
		cin >> b;
		int ans = max(A[i] * 10 + b, b * 10 + A[i]);
		cout << ans << " \n"[i == n - 1];
	}
}
