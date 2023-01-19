/*
Author: Nachiket Kanore
Created: Friday 06 November 2020 10:07:36 AM IST
Work out your own salvation. Do not depend on others.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 102, mod = 1e9 + 7;

int n, k, x;
int dp[N][N][N];

int go(int id, int currLen, int prev) {
	if (currLen > x)
		return 0;
	if (id == n + 1)
		return 1;
	int& ans = dp[id][currLen][prev];
	if (~ans)
		return ans;
	ans = 0;

	FOR(put, 1, k) {
		if (put <= prev) {
			ans = (ans + go(id + 1, 1, put)) % mod;
		} else {
			ans = (ans + go(id + 1, currLen + 1, put)) % mod;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
		Count the number of ways to create a sequence of N integers : A.
		such that each A[i] is [1, K] and length of any strictly increasing subarray
		is atmost X.
		2 ways A and B are considered different if there is atleast 1 index id,
		such that A[id] != B[id]
		K, X <= N <= 100
	*/

	cin >> n >> k >> x;
	memset(dp, -1, sizeof(dp));
	int ans = go(1, 0, 0);
	cout << ans;
}
