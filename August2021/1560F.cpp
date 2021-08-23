/**
 *    Author: Nachiket Kanore
 *    Created: Monday 23 August 2021 06:27:39 PM IST
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

bool dp[2][10][1<<10];
bool vis[2][10][1<<10];
int K;
string S;

bool go(int id, bool greaterTaken, int mask) {
	if (__builtin_popcount(mask) > K) return false;
	if (id == sz(S)) return true;

	bool &chk = vis[greaterTaken][id][mask];
	if (chk) return dp[greaterTaken][id][mask];

	chk = true;

	int from = 0, to = 9;
	if (!greaterTaken) from = S[id]-'0';
	bool found = false;

	FOR (dig,from,to) {
		found |= go(id + 1, greaterTaken || (dig > S[id]-'0'), mask | (1 << dig));
		if (found) break;
	}
	dp[greaterTaken][id][mask] = found;
	return found;
}

void trace(int id, bool greaterTaken, int mask) {
	if (id == sz(S)) return;

	int from = 0, to = 9;
	if (!greaterTaken) from = S[id]-'0';
	bool found = go(id, greaterTaken, mask);

	FOR (dig,from,to) {
		bool choice = go(id + 1, greaterTaken || (dig > S[id]-'0'), mask | (1 << dig));
		if (choice == found) {
			cout << dig;
			trace(id + 1, greaterTaken || (dig > S[id]-'0'), mask | (1 << dig));
			return;
		}
	}
	assert(false);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(vis, false, sizeof(vis));
		memset(dp, false, sizeof(dp));
		int N, K;
		cin >> N >> K;
		::K = K;
		S.clear();
		while (N) {
			S += (char)((N % 10) + '0');
			N /= 10;
		}
		reverse(ALL(S));
		bool found = go(0, 0, 0);
		assert(found);
		trace(0, 0, 0);
		cout << '\n';
	}
}
