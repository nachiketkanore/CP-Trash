/**
 *    Author: Nachiket Kanore
 *    Created: Friday 13 August 2021 04:28:56 PM IST
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

int solve(string S) {
	const int N = S.size();
	string keep;

	for (int i = 0; i < N;) {
		int j = i + 1;
		while (j < N && S[j] == S[i])
			++j;
		keep += S[i];
		i = j;
	}
	return N - (int)keep.size();
}

int32_t main() {
	cout << solve("LMLM") << '\n';
	cout << solve("LMMMMM") << '\n';
	cout << solve("LLLLLMMMMMM") << '\n';
}
