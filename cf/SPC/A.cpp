/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 12:02:55 PM IST
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
	// (a + 2k) mod b = 0
	// k >= 0
	// 2(a' + k) mod b = 0
	// (a' + k) mod b' = 0
	// always true?
	int T;
	cin >> T;
	while (T--) {
		cout << "YES\n";
	}
}
