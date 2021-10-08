/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 12:52:25 PM IST
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
#include <map>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int D, ret;
string S;
int dp[2][11];

bool go(int id, bool greaterTaken) {
	if (id == sz(S)) return true;
 
	auto& ans = dp[greaterTaken][id];
	if (~ans) return ans;
 
	int from = 0, to = 9;
	if (!greaterTaken) from = S[id]-'0';
	bool found = false;
 
	FOR (dig,from,to) {
		bool nextgreaterTaken = greaterTaken || (dig > S[id]-'0');
		if (dig == D) continue;
		found |= go(id + 1, nextgreaterTaken); 
		if (found) break;
	}
	ans = found;
	return found;
}
 
void trace(int id, bool greaterTaken) {
	if (id == sz(S)) return;
 
	int from = 0, to = 9;
	if (!greaterTaken) from = S[id]-'0';
	bool found = go(id, greaterTaken);
 
	FOR (dig,from,to) {
		bool nextgreaterTaken = greaterTaken || (dig > S[id]-'0');
		if (dig == D) continue;
		bool choice = go(id + 1, nextgreaterTaken);
		if (choice == found) {
			ret = ret * 10 + dig;
			trace(id + 1, nextgreaterTaken);
			return;
		}
	}
	assert(false);
}

int solve(int N, int D) {
	S.clear();
	int val = N;
	while (val) {
		S += (char)((val % 10) + '0');
		val /= 10;
	}
	reverse(ALL(S));
	F0R (i,sz(S)) F0R (j,2) dp[j][i] = -1;
	bool found = go(0, 0);
	ret = 0;
	if (found) { trace(0, 0); } 
	return ret;
}

int next_10(int N) {
	int ten = 1;
	while (ten < N) ten *= 10;
	return ten;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, D, ans = -1; cin >> N >> D;
		::D = D;
		FOR (i,N,N+200) {
			int val = i;
			bool ok = true;
			while (val && ok) {
				ok &= (val % 10) != D;
				val /= 10;
			}
			if (ok) {
				ans = i;
				break;
			}
		}
		if (~ans) {
			cout << (ans - N) << '\n';
			continue;
		}
		ans = solve(N, D);
		if (ans > 0) {
			cout << (ans - N) << '\n';
		} else {
			int old = N;
			N = next_10(N);
			ans = solve(N, D);
			assert(~ans);
			cout << (ans - old) << '\n';
		}
	}
}
