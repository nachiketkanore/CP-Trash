/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 03:03:32 PM IST
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		int cnt[101] = {};
		FOR (i,1,n) {
			int u; cin >> u;
			cnt[u]++;
		}
		const int INF = 1e9;
		int ans = INF;
		FOR (g,2,100) {
			bool poss = false;
			int have = 0;
			FOR (i,1,100) if (i % g == 0) {
				poss = true;
				have += cnt[i];
			}
			if (!poss) continue;
			cmin(ans, n - have);
		}
		assert(ans ^ INF);
		cout << ans << '\n';
	}
}
