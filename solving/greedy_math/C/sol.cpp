/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 08:58:36 PM IST
(ツ) The cosmos is neither moral or immoral; only people are. He who would move the world must first move himself.
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
	int one = 0, two = 0;

	FOR(i,1,n) {
		int u;
		cin >> u;
		one += u == 1;
		two += u == 2; 
	}

	if (two > 0) {
		--two;
		cout << 2 << " ";
	}

	if (one > 0) {
		--one;
		cout << 1 << " ";
	}

	while (two-->0) {
		cout << 2 << " ";
	}

	while (one-->0) {
		cout << 1 << " ";
	}
}
