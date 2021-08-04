/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 01:51:59 PM IST
(ツ) The most formidable weapon against errors of every kind is reason.
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

const int N = 1e5 + 5, inf = 1e18;

int n;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	int from = 1;
	int ans = 0;

	FOR (i,1,n) {
		int want;
		cin >> want;
		if (want > 0) {
			int to = from + want - 1;

			FOR (id, from, to) {
				ans += abs(id - i);
			}

			from = to + 1;
		}
	}

	cout << ans << "\n";
}
