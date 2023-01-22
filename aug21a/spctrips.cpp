/**
 *    Author: Nachiket Kanore
 *    Created: Friday 06 August 2021 05:05:22 PM IST
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

const int M = 1e5;
vector<int> divisors[M + 1];

int32_t main() {
	FOR(i, 1, M) for (int m = i; m <= M; m += i) divisors[m].push_back(i);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int ans = 0;
		FOR(B, 1, N) {
			for (int c : divisors[B])
				if (c < B) {
					ans += (N - c) / B + 1;
				}
		}
		cout << ans << '\n';
	}
}
