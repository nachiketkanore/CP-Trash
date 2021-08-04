/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 03:04:55 PM IST
(ツ) Almost everything comes from nothing.
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
	
	int n;
	cin >> n;

	vector<pair<int,int>> a(n);
	
	#define F first
	#define S second
	
	for (auto &it : a) cin >> it.F >> it.S;

	bool ok = false;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				ok |= (a[k].F - a[i].F) * (a[i].S - a[j].S) == (a[i].F - a[j].F) * (a[k].S - a[i].S);
			}
		}
	}
	cout << (ok ? "Yes" : "No");
}
