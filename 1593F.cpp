/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 16 October 2021 12:29:26 PM IST
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

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

#define int int16_t

const int INF = 1<<14;
int N, A, B;
char x[40];
int dp[2][2][40][82][40][40];

int go(int id, int diff, int modA, int modB, bool first, bool second) {
	if (id == N) {
		if (modA || modB) return INF;
		if (first && second) return abs(diff);
		return INF;
	}
	int& ans = dp[first][second][id][diff + 40][modA][modB];
	if (~ans) return ans;
	ans = INF;
	int curr = x[id]-'0';
	cmin(ans, go(id + 1, diff + 1, (modA * 10 + curr) % A, modB, first | true, second));
	cmin(ans, go(id + 1, diff - 1, modA, (modB * 10 + curr) % B, first, second | true));
	return ans;
}

void trace(int id, int diff, int modA, int modB, bool first, bool second) {
	if (id == N) { assert(first && second && !modA && !modB); return; }
	int& ans = dp[first][second][id][diff + 40][modA][modB];
	int curr = x[id]-'0';
	int one = go(id + 1, diff + 1, (modA * 10 + curr) % A, modB, first | true, second);
	if (one == ans) {
		cout << "R";
		trace(id + 1, diff + 1, (modA * 10 + curr) % A, modB, first | true, second);
		return;
	}
	int two = go(id + 1, diff - 1, modA, (modB * 10 + curr) % B, first, second | true);
	if (two == ans) {
		cout << "B";
		trace(id + 1, diff - 1, modA, (modB * 10 + curr) % B, first, second | true);
		return;
	}
	assert(0);
}
int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> N >> A >> B;
		F0R (i,N) { cin >> x[i]; }
		int best = go(0, 0, 0, 0, 0, 0);
		if (best >= INF) {
			cout << "-1\n";
			continue;
		}
		trace(0, 0, 0, 0, 0, 0);
		cout << '\n';
	}
}
