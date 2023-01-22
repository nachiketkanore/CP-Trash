/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 10:53:17 AM IST
(ツ) I have done my best: that is about all the philosophy of living one needs.
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

	int n;
	cin >> n;

	std::vector<int> pos;

	bool yes = false;

	FOR(i, 1, n) {
		int val;
		cin >> val;
		yes |= val == 1;
		if (val) {
			pos.push_back(i);
		}
	}

	if (!yes)
		cout << "0\n";
	else {
		int ans = 1;
		for (int i = 1; i < sz(pos); i++) {
			ans = ans * (pos[i] - pos[i - 1]);
		}
		cout << ans << "\n";
	}
}
