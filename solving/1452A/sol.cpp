/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 08:53:11 PM IST
(ツ) Everything that irritates us about others can lead us to an understanding about ourselves.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		int one = 2 * x;
		int two = 0;
		if (x != y) {
			two += (y - x)*2 - 1;
		}
		cout << (one + two) << "\n";
	}
}
