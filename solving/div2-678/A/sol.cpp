/*
Author: Nachiket Kanore
Created: Saturday 24 October 2020 07:22:52 PM IST
(ツ) If you're walking down the right path and you're willing to keep walking, eventually you'll make progress.
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
		int n, k;
		cin >> n >> k;
		int sum = 0;
		FOR(i,1,n) {
			int u;
			cin >> u;
			sum += u;
		}

		cout << (sum == k ? "YES\n" : "NO\n");
	}
}
