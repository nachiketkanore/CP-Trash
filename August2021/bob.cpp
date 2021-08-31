/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 31 August 2021 02:49:27 PM IST
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

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

bool dp[21][1000][1 << 12];
bool vis[21][1000][1 << 12];
int N, K, A[1010];
bool poss[1001000];

int go(int id, int rem, int OR) {
	if (rem < 0) return 0;
	if (id == N) {
		poss[OR] = true;
		return 1;
	}
	if (vis[rem][id][OR]) return dp[rem][id][OR];
	vis[rem][id][OR] = true;
	bool ans = 0;
	ans |= go(id + 1, rem, OR);
	ans |= go(id + 1, rem - 1, OR | A[id]);
	dp[rem][id][OR] = ans;
	return ans;
}

int32_t main() {
	memset(vis, false, sizeof(vis));
	cin >> N >> K;
	F0R (i,N) cin >> A[i];
	int _ = go(0, K, 0);
	int ans = 0;
	FOR (i,1,1000000) {
		if (poss[i]) {
			++ans;
		}
	}
	cout << ans << '\n';
}
