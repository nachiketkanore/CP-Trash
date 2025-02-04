/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 12:29:44 PM IST
 **/
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
	/* FOR (i,1,32) { */
	/* 	cout << bitset<8>(i) << '\n'; */
	/* } */
	vector<pair<int, int>> ranges;
	F0R(bit, 33) {
		ranges.push_back(make_pair(1LL << bit, (1LL << (bit + 1)) - 1));
	}
	int T;
	cin >> T;
	while (T--) {
		int N, ans = -1;
		cin >> N;
		for (auto [L, R] : ranges) {
			if (L > N)
				continue;
			if (R <= N) {
				cmax(ans, R - L + 1);
			} else {
				cmax(ans, N - L + 1);
			}
		}
		assert(~ans);
		cout << ans << '\n';
	}
}
