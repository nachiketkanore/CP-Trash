/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 31 August 2021 02:17:46 PM IST
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

#define ll int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

string N;
ll dp[2][20][20 * 9][20 * 81];

ll go(int id, bool smallTaken, int sod, int ssod) {
	if (id == sz(N)) return __gcd(sod, ssod) == 1;
	ll &ans = dp[smallTaken][id][sod][ssod];
	if (~ans) return ans;
	ans = 0;
	FOR (dig,0,(smallTaken? 9 : N[id]-'0')) {
		ans += go(id + 1, smallTaken || (dig < N[id]-'0'), sod + dig, ssod + dig * dig);
	}
	return ans;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		ll L, R;
		cin >> L >> R;
		auto solve = [](ll n) {
			::N = to_string(n);
			return go(0, 0, 0, 0);
		};
		cout << solve(R) - solve(L - 1) << '\n';
	}
}
