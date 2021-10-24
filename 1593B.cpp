/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 October 2021 11:53:30 AM IST
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

const int INF = 1e9;
int dp[18][25];

int solve(int id, int mod, const string &S) {
	if (id == sz(S)) return mod == 0 ? 0 : INF;
	int8_t curr = S[id]-'0';
	int &ans = dp[id][mod];
	if (~ans) return ans;
	ans = INF;
	cmin(ans, 1 + solve(id + 1, mod, S));
	cmin(ans, 0 + solve(id + 1, (mod * 10 + curr) % 25, S));
	return ans;
}

int32_t main() {
	// Longest subsequence with value % 25 == 0
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		string S; cin >> S;
		int ans = solve(0, 0, S);
		cout << ans << '\n';
	}
}
