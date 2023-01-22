/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 12:42:10 PM IST
(ツ) In three words I can sum up everything Ive learned about life: it goes on.
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

const int N = 1e3 + 5, inf = 1e18;

int k, n;
string one, two;
int dp[N][N];

int go(int id, int correct) {
	if (correct > k)
		return -inf;
	if (id == n + 1) {
		return (correct == k ? 0 : -inf);
	}

	int& ans = dp[id][correct];
	if (~ans)
		return ans;
	ans = -inf;

	// it is correct
	int get = (one[id] == two[id]) + go(id + 1, correct + 1);
	ans = max(ans, get);

	// it is incorrect
	get = (one[id] != two[id]) + go(id + 1, correct);
	ans = max(ans, get);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	cin >> one >> two;
	assert(sz(one) == sz(two));
	one = " " + one;
	two = " " + two;
	n = sz(one) - 1;
	memset(dp, -1, sizeof(dp));
	int ans = go(1, 0);
	cout << ans;
}
