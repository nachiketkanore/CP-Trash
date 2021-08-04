/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 07:50:45 PM IST
(ツ) A goal is a dream with a deadline.
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
	cout << n << "\n";
	FOR (i,1,n) {
		cout << (n - i + 1) << " ";
	}
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		solve();
	}
}
