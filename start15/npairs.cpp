/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 17 October 2021 02:29:15 PM IST
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
		int N, ans = 0;
		string S;
		cin >> N >> S;
		F0R(i, N) {
			for (int j = i - 1; j >= 0 && (i - j <= 10); j--) {
				if (i - j == abs(S[i] - S[j]))
					++ans;
			}
		}
		cout << ans << '\n';
	}
}
