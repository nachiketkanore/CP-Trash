/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 08:03:50 PM IST
(ツ) A fine quotation is a diamond on the finger of a man of wit, and a pebble in the hand of a fool.
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
	
	int T;	cin >> T;
	while (T--) {
		int L, R;
		cin >> L >> R;
		int a = R + 1;
		if (2 * (L % a) >= a) cout << "YES\n";
		else cout << "NO\n";
	}
}
