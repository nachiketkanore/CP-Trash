/*
Author: Nachiket Kanore
Created: Sunday 22 November 2020 05:25:16 PM IST
(ツ) As we express our gratitude, we must never forget that the highest appreciation is not to utter words, but to live by them.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	FOR(i, 1, n) {
		char ch;
		cin >> ch;
		if (ch == 'o') {
			x = x + 1;
		} else {
			x = x - 1;
			if (x <= 0)
				x = 0;
		}
	}
	cout << x;
}
