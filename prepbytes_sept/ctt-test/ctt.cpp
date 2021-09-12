/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 03:16:47 PM IST
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
#include <map>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

string N;
int K;
map<int,int> dp[2][2][20];

int go(int id, bool smalltaken, int prod, bool started = false) {
	if (id == sz(N)) return prod <= K;
	if (dp[smalltaken][started][id].count(prod))
		return dp[smalltaken][started][id][prod];
	int ans = 0;
	const int curr = N[id]-'0';
	int from = 0;
	int to = 9;
	if (!smalltaken)
		to = curr;
	FOR (dig,from,to) {
		bool nstarted = started || (dig > 0);
		ans += go(id + 1, smalltaken || dig < curr, nstarted? prod * dig: 1, nstarted);
	}
	dp[smalltaken][started][id][prod] = ans;
	return ans;
}

int32_t main() {
	cin >> N >> K;
	int ans = go(0, 0, 1, 0) - 1;
	assert(ans >= 0);
	cout << ans << '\n';
}
