/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:55:00 PM IST
(ツ) The aim of life is self-development. To realize ones nature perfectly that is what each of us is here for.
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

int n;

int go(int id, int chosen) {
	if (chosen > n / 2)
		return 0;
	if (id == n + 1) {
		return (chosen == n / 2);
	}

	int ans = 0;
	int c1 = go(id + 1, chosen);
	int c2 = go(id + 1, chosen + 1);
	ans = c1 + c2;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	cout << go(1, 0);
}
