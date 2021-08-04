/*
Created: Saturday 21 November 2020 07:56:00 PM IST
(ツ) We are what we repeatedly do. Excellence, then, is not an act, but a habit.
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



void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "0\n";
		return ;
	}
	if (n == 2) {
		cout << "1\n";
		return ;
	}
	if (n == 3) {
		cout << "2\n";
		return ;
	}
	if (n % 2 == 0) {
		cout << "2\n";
		return ;
	}
	cout << "3\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve();
}
