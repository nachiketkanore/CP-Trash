/*
Author: Nachiket Kanore
Created: Friday 01 January 2021 08:13:18 PM IST
(ツ) Who looks outside, dreams; who looks inside, awakes.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
int n,k;
const int N = 101;

int a[N];
int dp[N][N][N];

int f(int id, int sum_of_first, int sum_of_second) {
    if(sum_of_first >= k && sum_of_second >= k) return 0;
    if(id >= n) return n+1;
    if(dp[id][sum_of_first][sum_of_second] != -1) return dp[id][sum_of_first][sum_of_second];
    int choice1 = f(id+1,sum_of_first,sum_of_second); // leave this element;
    int choice2 = 1+f(id+1,min(sum_of_first+a[id], k),sum_of_second); // give it to first 
    int choice3 = 1+f(id+1,sum_of_first,min(k, sum_of_second+a[id])); // give it to second
    int ans = min({choice1,choice2,choice3});
    return dp[id][sum_of_first][sum_of_second] = ans;
}

int solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    memset(dp,-1,sizeof(dp));
    int ans = f(0,0,0);
    if (ans > n) ans = -1;
    return ans;
}

int SOLVE() {
	
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int ans = solve();
		assert(ans == SOLVE());
	}
}
