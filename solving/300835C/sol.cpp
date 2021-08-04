/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 06:49:10 PM IST
(ツ) It is never too late to be what you might have been.
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

int SOD(int n) {
	return (!n ? 0 : n % 10 + SOD(n / 10));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int x;
		cin >> x;

		bool ok = false;
		for (int y = 11; y <= 100 && !ok; y++) {
			if (SOD(x) == SOD(y * x)) {
				cout << y << "\n";
				ok =
			}
		}

		assert(ok);
	}
}
