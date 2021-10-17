/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 17 October 2021 02:21:23 PM IST
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
	int T;
	cin >> T;
	while (T--) {
		int ind = 0, eng = 0;
		F0R (i,5) {
			int who; cin >> who;
			ind += who == 1;
			eng += who == 2;
		}
		if (ind == eng) cout << "DRAW\n";
		else if (ind > eng) cout << "INDIA\n";
		else cout << "ENGLAND\n";
	}
}
