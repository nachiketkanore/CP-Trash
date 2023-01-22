/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 August 2021 03:39:40 PM IST
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

string S;
int N;

bool overflow(int x, int y) {
	int fact = 1;
	FOR(i, 1, x) {
		fact *= i;
		if (fact > y)
			return true;
	}
	return false;
}

int go(int id, int len, bool smallTaken, int prod, bool started) {
	if (started && prod == 0)
		return 0;
	if (overflow(len, prod))
		return 0;
	if (id == N)
		return 1;

	int curr = S[id] - '0';
	int ans = 0;
	int L = 0, R = 9;
	if (started)
		L = 1;
	if (!smallTaken)
		R = curr;

	FOR(dig, L, R) {

		int nlen = (started || dig ? len + 1 : 0);
		bool nsmallTaken = smallTaken || (dig < curr);

		ans += go(id + 1, nlen, nsmallTaken, prod * dig, started || dig > 0);
	}
	return ans;
}

int solve() {
	N = S.size();
	return go(0, 0, 0, 1, 0);
}

int32_t main() {
	// observations:
	// 0 cannot be included, product will be 0, then product <= factorial
	// once factorial > product it will always remain the factorial > product
	// answer shouldn't be MODDED?
	// is answer < 10^18

	int T;
	cin >> T;
	while (T--) {
		cin >> S;
		cout << solve() << '\n';
	}
}
