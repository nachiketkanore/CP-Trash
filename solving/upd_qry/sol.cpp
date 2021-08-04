/*
Author: Nachiket Kanore
Created: Sunday 01 November 2020 11:48:37 AM IST
(ツ) Your work is to discover your world and then with all your heart give yourself to it.
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

struct treeNode {
	int mn = inf;
	int mx = -inf;
} tree[N << 2];

int n, q, a[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	FOR (i,1,n) {
		cin >> a[i];
		upd(i, a[i]);
	}

	while (q--) {
		char ch;
		cin >> ch;
		if (ch == 'U') {
			int id, val;
			cin >> id >> val;
			upd(id, val);
			a[id] = val;
		} else {
			int from, C;
			cin >> from >> C;
			int L = a[from] - C, R = a[from] + C;
			assert(L <= R);

			// max id such that max[from, id] <= R
			int r1 = 

			// max id such that min[from, id] >= L
			int r2 =

			int r = min(r1, r2);
			assert(from <= r);
			cout << (r - from + 1) << "\n";
		}
	}
}
