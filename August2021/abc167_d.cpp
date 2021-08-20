/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 07:09:14 PM IST
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

template<typename T>
void read(T& one) { cin >> one; }

template <typename T, typename... Tn>
void read(T& one, Tn&... args) { cin >> one; read(args...); }

int32_t main() {
	const int LOG = 63;
	int N, K;
	read(N, K);
	vector<vector<int>> to(LOG, vector<int> (N, -1));
	F0R (i,N) {
		cin >> to[0][i];
		--to[0][i];
	}
	F0R (j,LOG) if (j) F0R (i,N) to[j][i] = to[j-1][to[j-1][i]];
	int now = 0;
	F0R (j,LOG) if (K >> j & 1LL) now = to[j][now];
	cout << ++now << '\n';
}
