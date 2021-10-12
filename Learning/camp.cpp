/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 01 September 2021 09:11:53 PM IST
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

const int INF = 1e18;
const int _ = 3003;
int N, X, Y, A[_], B[_];
int dp[3003][2020];

int go(int id, int one, int two) {
	if (one < 0 || two < 0) return INF;
	if (id == N + 1) return 0;
	int &ans = dp[id][one];
	if (~ans) return ans;
	ans = INF;
	cmin(ans, A[id] + go(id + 1, one - 1, two));
	cmin(ans, B[id] + go(id + 1, one, two - 1));
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> X >> Y;
	FOR (i,1,N) { cin >> A[i] >> B[i]; }
	cout << go(1, X, Y);
}
