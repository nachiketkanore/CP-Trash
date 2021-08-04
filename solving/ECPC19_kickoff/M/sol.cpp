/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 03:55:10 PM IST
(ツ) You only lose what you cling to.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int SOD(int n) { return (!n ? 0 : n%10 + SOD(n/10)); }

int LIS(int n) {
	vector<int> a(n+1), dp(n+1, 1);
	FOR (i,1,n) a[i] = SOD(i);
	FOR (i,1,n) FOR (j,i,n) if (a[i] < a[j]) dp[j] = max(dp[j], 1+dp[i]);
	return *max_element(dp.begin(), dp.end());
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	FOR (i,1,1000) {
		cout << LIS(i) << "\n";
	}
}
