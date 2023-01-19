/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 August 2021 03:50:38 PM IST
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
#define int int64_t
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

const int N = 1e7;
int cnt[N + 5];

int32_t main() {
	srand(time(0));
	FOR(i, 1, N) {
		int u = i;
		int len = 0;
		int prod = 1;
		while (u > 0) {
			len++;
			prod *= u % 10;
			u /= 10;
		}
		int fact = 1;
		while (len > 1) {
			fact *= len;
			len--;
		}
		cnt[i] = cnt[i - 1] + (prod >= fact);
	}
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		string S;
		cin >> S;
		if (sz(S) <= 8) {
			int n = stoll(S);
			if (n <= N)
				cout << cnt[n] << '\n';
			else
				assert(false);
		} else {
			assert(false);
		}
	}
}
