/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 October 2021 04:35:16 PM IST
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

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int digs(int N) {
	return (N == 0 ? 0 : 1 + digs(N / 10));
}

const int MOD = 1e9 + 7;
int p10[100];

int32_t main() {
	p10[0] = 1;
	for (int i = 1; i < 100; i++) {
		p10[i] = 10 * p10[i-1] % MOD;
	}
	int N, ans = 0;
	cin >> N;
	F0R (i,N) {
		int v; cin >> v;
		ans = ans * p10[digs(v)] + v;
		ans %= MOD;
	}
	cout << ans;
}
