/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 29 August 2021 03:26:02 PM IST
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

const int INF = 1e9;

void solve() {
	string S;
	cin >> S;
	int K;
	cin >> K;
	int cost[26][26];
	F0R(i, 26) F0R(j, 26) cost[i][j] = INF;
	F0R(i, 26) cost[i][i] = 0;
	while (K--) {
		char from, to;
		cin >> from >> to;
		cost[from - 'A'][to - 'A'] = 1;
	}
	F0R(k, 26) F0R(i, 26) F0R(j, 26) cmin(cost[i][j], cost[i][k] + cost[k][j]);
	int ans = INF;
	F0R(make, 26) {
		int req = 0;
		F0R(i, sz(S)) req += cost[S[i] - 'A'][make];
		cmin(ans, req);
	}
	if (ans >= INF)
		ans = -1;
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
