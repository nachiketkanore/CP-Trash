/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 12:47:21 PM IST
(ツ) What we think determines what happens to us, so if we want to change our lives, we need to stretch our minds.
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

const int N = 200, inf = 1e18;

int n;
string s;
int dp[26][26][N];

int go(int id, char prev1, char prev2) {
	if (id == n)
		return 1;

	int& ans = dp[prev1 - 'a'][prev2 - 'a'][id];
	if (~ans)
		return ans;
	ans = 0;

	if (s[id] >= prev1) {
		ans |= go(id + 1, s[id], prev2);
	}
	if (s[id] >= prev2) {
		ans |= go(id + 1, prev1, s[id]);
	}
	return ans;
}

void trace(int id, char prev1, char prev2) {
	if (id == n)
		return;
	int ans = go(id, prev1, prev2);
	assert(ans);

	if (s[id] >= prev1) {
		int get = go(id + 1, s[id], prev2);
		if (get == ans) {
			cout << "0";
			return trace(id + 1, s[id], prev2);
		}
	}
	if (s[id] >= prev2) {
		int get = go(id + 1, prev1, s[id]);
		if (get == ans) {
			cout << "1";
			return trace(id + 1, prev1, s[id]);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	memset(dp, -1, sizeof(dp));
	int poss = go(0, 'a', 'a');
	if (!poss) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		trace(0, 'a', 'a');
	}
}
