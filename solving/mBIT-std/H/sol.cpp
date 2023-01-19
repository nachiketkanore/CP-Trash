/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 02:14:42 PM IST
(ツ) If one way be better than another, that you may be sure is natures way.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e6 + 5;
string s;
int n;
map<int, int> vals;
int dp[N];

int go(int id) {
	if (id == n)
		return 1;
	int& ans = dp[id];
	if (~ans)
		return ans;
	ans = 0;

	for (int to = id; to < id + 3 && to < n; to++) {
		int val = 0;
		FOR(i, id, to) val = val * 10 + (s[i] - '0');
		if (vals.count(val)) {
			ans |= go(to + 1);
		}
	}
	return ans;
}

void trace(int id) {
	if (id >= n)
		return;
	int ans = go(id);
	assert(ans);

	for (int to = id; to < id + 3 && to < n; to++) {
		int val = 0;
		FOR(i, id, to) val = val * 10 + (s[i] - '0');
		if (go(to + 1) && vals.count(val)) {
			cout << vals[val];
			return trace(to + 1);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();

	FOR(i, 0, 9) {
		vals[i * i] = i;
		vals[i * i * i] = i;
	}
	memset(dp, -1, sizeof(dp));
	int ans = go(0);
	if (ans) {
		trace(0);
	} else {
		cout << "-1\n";
	}
}
