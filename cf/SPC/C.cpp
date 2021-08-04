/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 12:17:08 PM IST
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
	// all odd to even
	// aim: all even | x odd x even (2n - 2x) even
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		int N = n << 1;
		int even = 0, odd = 0;
		F0R (i,N) {
			int u; cin >> u;
			even += u % 2 == 0;
			odd += u % 2 == 1;
		}
		int ans = odd;
		if (even >= n) cmin(ans, int(0));
		else cmin(ans, n - even);
		cmin(ans, n);
		cout << ans << '\n';
	}
}
