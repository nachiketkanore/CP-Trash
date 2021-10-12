/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 August 2021 09:19:09 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int _ = 1010;
int N, S[_], G[_];

int go(int id, int bal) {
	if (id > N) return 0;
	int ans = 0;
	int c1 = bal + S[id];
	int c2 = bal - G[id];
	ans += (c1 == 0) + go(id + 1, c1);
	ans += (c2 == 0) + go(id + 1, c2);
	return ans;
}

int* ReArrangeArray(int* arr, int len) {
	vector<int> neg, pos;
	for (int i = 0; i < len; i++) {
		if (arr[i] >= 0) pos.push_back(arr[i]);
		else neg.push_back(arr[i]);
	}
	int id = 0;
	for (int x: neg) arr[id++] = x;
	for (int x: pos) arr[id++] = x;
	return arr;
}

int PossibleWays(int n, int m) {
	if (n == 0) return -1;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i >= j)
				dp[i] += dp[i - j];
		}
	}
	return dp[n];
}

int32_t main() {
	int T = 10, tc = 0;
	while (tc++^T) {
		cout << tc << '\n';
	}
	/* int a[] = {1, 7, -5, 9, -12, 15}; */
	/* int* ans = ReArrangeArray(a, 6); */
	/* for (int i = 0; i < 6; i++) { */
	/* 	cout << ans[i] << ' '; */
	/* } */
	/* cout << PossibleWays(3, 2); */
	/* cin >> N; */
	/* FOR (i,1,N) cin >> S[i]; */
	/* FOR (i,1,N) cin >> G[i]; */
	/* int ans = 0; */
	/* FOR (i,1,N) { ans += go(i, 0); } */
	/* cout << ans << '\n'; */
}
