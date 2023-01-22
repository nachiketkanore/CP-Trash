/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 24 August 2021 04:41:58 PM IST
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

const int MOD = 1e9 + 7;
string S;
const string T = "chokudai";
int dp[12][100005];

int go(int i, int j) {
	if (j == sz(T))
		return 1;
	if (i == sz(S))
		return 0;
	int& ans = dp[j][i];
	if (~ans)
		return ans;
	ans = 0;
	ans += go(i + 1, j);
	if (S[i] == T[j])
		ans += go(i + 1, j + 1);
	ans %= MOD;
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> S;
	cout << go(0, 0);
}
