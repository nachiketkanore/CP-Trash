/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 02:07:14 PM IST
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

using ll = long long;
const ll INF = 1e10;

string S;
int K;
ll dp[11][1<<10][2][2];

ll go(int i, int mask, bool smalltaken, bool started) {
	if (__builtin_popcount(mask) > K) return 0;
	if (i == sz(S)) return 1 && started;
	ll &ans = dp[i][mask][smalltaken][started];
	if (~ans) return ans;
	ans = 0;
	int from = 0, to = 9;
	if (!smalltaken) to = S[i]-'0';
	
	FOR (dig,from,to) {
		int nmask = mask;
		if (dig || started) nmask |= 1 << dig;
		ans += go(i+1, nmask, smalltaken || (dig < S[i]-'0'), started || dig > 0);
	}
	return ans;
}

ll count_beautiful(int N, int K) {
	S.clear();
	::K = K;
	while (N) S += (char)((N % 10) + '0'), N /= 10;
	reverse(ALL(S));
	F0R (i,sz(S)) F0R (j,1<<10) F0R (x,2) F0R (y,2) dp[i][j][x][y] = -1;
	return go(0, 0, 0, 0);
}

int count_beautiful(int L, int R, int K) {
	return count_beautiful(R, K) - count_beautiful(L - 1, K);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		ll lo = N, hi = INF;
		int ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (count_beautiful(N, mid, K) > 0) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		assert(~ans);
		cout << ans << '\n';
	}
}
