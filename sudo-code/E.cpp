/**
 *    Author: Nachiket Kanore
 *    Created: Monday 08 November 2021 07:36:32 PM IST
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

const int _ = 1010;
vector<int> g[_];

int dp2[_];

int go(int u) {
	int& ans = dp2[u];
	if (~ans)
		return ans;
	ans = 0;
	for (int v : g[u]) {
		cmax(ans, 1 + go(v));
	}
	return ans;
}

int dp[_][20005];

int go(int u, int len) {
	if (len == 0)
		return 1;
	int& ans = dp[u][len];
	if (~ans)
		return ans;
	ans = 0;
	for (int v : g[u]) {
		ans += go(v, len - 1);
	}
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	int N;
	cin >> N;
	int A[N];
	F0R(j, N) {
		cin >> A[j];
		F0R(i, j) if (A[i] < A[j]) {
			g[i].push_back(j);
		}
	}
	int mx = 0;
	F0R(i, N) {
		cmax(mx, go(i));
	}
	int ans = 0;
	F0R(i, N) {
		ans += go(i, mx);
	}
	cout << ans;
}
