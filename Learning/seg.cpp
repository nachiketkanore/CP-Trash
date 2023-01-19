/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 September 2021 07:08:55 PM IST
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

const int _ = 1e5 + 5;
int N, Q, A[_];

int32_t main() {
	cin >> N >> Q;
	FOR(i, 1, N) {
		cin >> A[i];
	}
	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int L, R, V;
			cin >> L >> R >> V;
			FOR(i, L, R) A[i] += V;
		} else if (type == 2) {
			int L, R, brute = 0;
			cin >> L >> R;
			FOR(i, L, R) {
				brute += (A[i] + 5 - 1) / 5;
			}
			cout << brute << '\n';
		}
	}
}
