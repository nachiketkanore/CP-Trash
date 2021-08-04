/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 11:37:47 PM IST
(ツ) Were here for a reason. I believe a bit of the reason is to throw little torches out to lead people through the dark.
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
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1000 + 5, inf = 1e18;

int n, p, str[N];
int dp[2][28][28][N];

void print(int id) {
	assert(id >= 1 && id <= p);
	char ch = (char)('a' + id - 1);
	cout << ch;
}

int go(int id, int prev1, int prev2, bool takenGreater) {
	if (id == n + 1)
		return takenGreater;
	int &ans = dp[takenGreater][prev1][prev2][id];
	if (~ans) return ans;
	ans = 0;

	int curr = str[id];

	FOR(ch, 1, p) {
		if (prev1 == ch || prev2 == ch) continue;
		if (takenGreater) {
			ans |= go(id + 1, ch, prev1, takenGreater);
		} else {
			if (ch >= curr)
				ans |= go(id + 1, ch, prev1, takenGreater || (ch > curr));
		}
	}
	return ans;
}

void trace(int id, int prev1, int prev2, bool takenGreater) {
	if (id == n + 1)
		return ;
	int ans = go(id, prev1, prev2, takenGreater);

	int curr = str[id];

	FOR(ch, 1, p) {
		if (prev1 == ch || prev2 == ch) continue;
		if (takenGreater) {
			int get = go(id + 1, ch, prev1, takenGreater);
			if (ans == get) {
				print(ch);
				return trace(id + 1, ch, prev1, takenGreater);
			}
		} else {
			if (ch < curr) continue;
			int get = go(id + 1, ch, prev1, takenGreater || (ch > curr));
			if (ans == get) {
				print(ch);
				return trace(id + 1, ch, prev1, takenGreater || (ch > curr));
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> p;
	FOR(i,1,n) {
		char ch;	cin >> ch;
		str[i] = ch - 'a' + 1;
	}

	memset(dp, -1, sizeof(dp));
	int ans = go(1, 0, 0, 0);
	if (!ans) {
		cout << "NO\n";
	} else {
		trace(1, 0, 0, 0);
	}
}
