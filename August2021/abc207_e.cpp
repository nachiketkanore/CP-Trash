/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 24 August 2021 04:54:03 PM IST
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

const int _ = 3003;
const int MOD = 1e9 + 7;
int N, A[_], dp[_][_];

int go(int from, int id) {
	if (from == N + 1) return 1;
	int& ans = dp[from][id];
	if (~ans) return ans;
	ans = 0;
	int sum = 0;
	FOR (to,from,N) {
		sum += A[to];
		if (sum % id == 0) {
			ans += go(to + 1, id + 1);
			if (ans >= MOD)
				ans -= MOD;
		}
	}
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR (i,1,N) cin >> A[i];
	cout << go(1, 1) << '\n';
}
