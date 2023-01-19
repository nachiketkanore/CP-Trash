/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 04:50:31 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int INF = 1e9;
const int LIM = 300;
int N, dp[110][505];
string S;

int go(int id, int bal) {
	if (bal < 0 || bal > LIM)
		return INF;
	if (id == N)
		return bal;
	int& ans = dp[id][bal];
	if (~ans)
		return ans;
	ans = INF;
	cmin(ans, 1 + go(id, bal + 1));
	cmin(ans, 1 + go(id, bal - 1));
	cmin(ans, 0 + go(id + 1, bal + (S[id] == '(' ? +1 : -1)));
	return ans;
}

void trace(int id, int bal) {
	if (bal < 0 || bal > LIM)
		assert(false);
	if (id == N) {
		while (bal--)
			cout << ')';
		return;
	}
	int ans = go(id, bal);
	int c1 = 1 + go(id, bal + 1);
	if (c1 == ans) {
		cout << '(';
		trace(id, bal + 1);
		return;
	}
	int c3 = 0 + go(id + 1, bal + (S[id] == '(' ? +1 : -1));
	if (c3 == ans) {
		cout << S[id];
		trace(id + 1, bal + (S[id] == '(' ? +1 : -1));
		return;
	}
	int c2 = 1 + go(id, bal - 1);
	if (c2 == ans) {
		cout << ')';
		trace(id, bal - 1);
		return;
	}
	assert(false);
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> S;
	int len = go(0, 0);
	assert(len <= N);
	trace(0, 0);
}
