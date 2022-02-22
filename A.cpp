/**
 *    Author: Nachiket Kanore
 *    Created: Friday 12 November 2021 12:26:55 PM IST
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

const int _ = 1e5 + 5;
int N, L[_], R[_];
vector<int> g[_];
int dp[2][_];

int go(int u, int which, int par = 1) {
	int &ans = dp[which][u];
	if (~ans) return ans;
	ans = 0;
	for (int v: g[u]) {
		if (v == par) continue;
		if (which == 0) {
			ans += max(abs(L[u] - L[v]) + go(v, 0, u), abs(L[u] - R[v]) + go(v, 1, u));
		} else {
			ans += max(abs(R[u] - L[v]) + go(v, 0, u), abs(R[u] - R[v]) + go(v, 1, u));
		}
	}
	return ans;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		FOR (i,1,N) { F0R (j,2) dp[j][i] = -1; g[i].clear(); cin >> L[i] >> R[i]; }
		F0R (i,N-1) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << max(go(1, 0), go(1, 1)) << '\n';
	}
}
