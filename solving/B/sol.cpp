/*
Author: Nachiket Kanore
Created: Friday 13 November 2020 08:04:54 PM IST
(ツ) Though no one can go back and make a brand new start, anyone can start from not and make a brand new ending.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	int b[n + 1] = {};
	FOR (i,1,n) cin >> b[i];
	sort(b + 1, b + n + 1);
	FOR (i,2,n) if (b[i] == b[i-1]) {
		cout << "YES\n";
		return ;
	}
	cout << "NO\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
