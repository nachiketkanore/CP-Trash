/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 January 2022 03:17:20 PM IST
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

const int _ = 105;
const int INF = 1e18;
int N, M, K, C[_], cost[_][_], dp[_][_][_];

int go(int id, int prev, int group_id) {
    if (id > N) {
        if (group_id == K + 1) return 0;
        return INF;
    }
    int &ans = dp[id][prev][group_id];
    if (~ans) return ans;
    ans = INF;
    if (C[id]) {
        int req = go(id + 1, C[id], group_id + (prev != C[id]));
        cmin(ans, req);
    } else {
        FOR (color,1,M) {
            int req = cost[id][color] + go(id + 1, color, group_id + (prev != color));
            cmin(ans, req);
        }
    }
    return ans;
}

int32_t main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> M >> K;
    FOR (i,1,N) cin >> C[i];
    FOR (i,1,N) FOR (j,1,M) cin >> cost[i][j];
    int ans = go(1, 0, 1);
    if (ans >= INF) ans = -1;
    cout << ans << '\n';
}
