/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 05:58:11 PM IST
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
	int N, M, K, ans = 0;
	cin >> N >> M >> K;
	char mat[N][M];
	F0R(i, N) F0R(j, M) cin >> mat[i][j];
	F0R(rows, 1 << N) {
		F0R(cols, 1 << M) {
			int get = 0;
			F0R(i, N) F0R(j, M) if (mat[i][j] == '#') {
				if ((rows >> i & 1) || (cols >> j & 1))
					continue;
				++get;
			}
			ans += get == K;
		}
	}
	cout << ans << '\n';
}
