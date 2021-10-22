/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 October 2021 04:15:41 PM IST
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

void solve() {
	int X, Y; cin >> X >> Y;
	if (Y <= X) cout << X - Y << '\n';
	else {
		int ans = 0;
		while (X < Y) {
			++ans;
			X += 2;
		}
		assert(X == Y or X == Y + 1);
		ans += X != Y;
		cout << ans << '\n';
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
