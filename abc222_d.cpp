/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 October 2021 04:26:25 PM IST
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
#include <functional>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int dp[3005][3005];
int dp2[3005][3005];

int32_t main() {
	int N; cin >> N; 
	int A[N], B[N];
	F0R (i,N) cin >> A[i];
	F0R (i,N) cin >> B[i];

	const int MOD = 998244353;

	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));

	auto add_mod = [](int &x, int add) {
		x += add;
		if (x >= MOD)
			x -= MOD;
		return x;
	};

	function<int(int,int)> go = [&](int id, int prev) {
		if (prev < 0) return int(0);
		if (id == 0) return int(1);

		int &ans = dp[id][prev];
		if (~ans) return ans;
		ans = pref_sum(id - 1, prev);
		return ans;
	};

	function<int(int,int)> pref_sum = [&](int id, int last) {
		if (id < 0 || last < 0) return int(0);
		int &ans = dp2[id][last];
		if (~ans) return ans;
		ans = go(id, last) + pref_sum(id, last - 1);
		if (ans >= MOD) ans -= MOD;
		return ans;
	};

	int ans = 0;
	FOR (last_val, A[N-1], B[N-1]) {
		add_mod(ans, go(N-1, last_val));
	}
	cout << ans << '\n';
}
