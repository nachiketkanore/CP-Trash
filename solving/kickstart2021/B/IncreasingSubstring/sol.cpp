/*
Author: Nachiket Kanore
Created: Monday 19 April 2021 09:59:37 AM IST
*/
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		if (s[i-1] < s[i]) {
			dp[i] += dp[i-1];
		}
	}
	F0R (i,n) cout << dp[i] << " \n"[i==n-1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; 
	FOR (tc,1,T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
