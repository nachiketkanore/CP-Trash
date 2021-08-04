/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 10:50:58 PM IST
(ツ) When in doubt, tell the truth.
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
	vector<int> a(n);
	int GCD = 0;

	for (int &x : a) {
		cin >> x;
		GCD = __gcd(GCD, x);
	}

	if (GCD != 1) {
		cout << -1;
	} else {
		bool found = false;
		FOR(i,1,n) FOR(j,i+1,n) {
			int g = __gcd(a[i], a[j]);
			found |= g == 1;
			if (g == 1) {
				int cost = 
			}
		}

		assert(found);
	}
}
