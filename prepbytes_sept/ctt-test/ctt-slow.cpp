/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 03:32:19 PM IST
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

int32_t main() {
	int N, K, ans = 0;
	cin >> N >> K;
	FOR (i,1,N) {
		int prod = 1;
		for (int val = i; val > 0; val = val / 10) {
			prod = prod * ( val % 10 );
		}
		if (prod <= K)
			++ans;
	}
	cout << ans << '\n';
}
