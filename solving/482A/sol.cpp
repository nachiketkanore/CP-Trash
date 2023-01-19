/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 03:40:15 PM IST
(ツ) There is nothing impossible to him who will try.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void chk(int n, int k) {

	std::vector<int> a(n);
	FOR(i, 1, n) a[i - 1] = i;
	vector<int> ans;

	do {
		set<int> vals;
		for (int i = 1; i < n; i++) {
			vals.insert(abs(a[i] - a[i - 1]));
		}
		if (sz(vals) == k) {
			// for (int x : a) cout << x << ' ';
			// 	cout << '\n';
			// cout << '\n';
			ans = a;
			// return;
		}
	} while (next_permutation(a.begin(), a.end()));

	for (int x : ans)
		cout << x << ' ';
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	chk(8, 1);
	chk(8, 2);
	chk(8, 3);
	chk(8, 4);
	chk(8, 5);
	chk(8, 6);
	chk(8, 7);
}
