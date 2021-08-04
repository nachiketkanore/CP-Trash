/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 11:28:30 PM IST
(ツ) What we achieve inwardly will change outer reality.
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
const int M = 1e6;

int tot[M + 5];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	FOR(i,1,n) {
		int cnt;
		cin >> cnt;

		FOR(j,1,cnt) {
			int L, R;
			cin >> L >> R;
			tot[L]++, tot[R + 1]--;
		}
	}

	FOR(i,1,M) {
		tot[i] += tot[i - 1];
		if (tot[i] == 0) {
			cout << i << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}
