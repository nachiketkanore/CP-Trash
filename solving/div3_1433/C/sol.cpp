/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:03:33 PM IST
(ツ) Begin, be bold, and venture to be wise.
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

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a;
		vector<int> vals(n + 2, inf);
		FOR(i, 1, n) {
			int val;
			cin >> val;
			vals[i] = val;
			a.push_back({ val, i });
		}
		sort(a.begin(), a.end());

		if (a[0].first == a.back().first)
			cout << "-1\n";
		else {
			int which = -1;
			int mx = a.back().first;
			for (auto it : a)
				if (it.first == mx) {
					int id = it.second;
					if (id - 1 >= 1)
						if (vals[id - 1] != mx)
							which = id;
					if (id + 1 <= n)
						if (vals[id + 1] != mx)
							which = id;
				}
			cout << which << "\n";
		}
	}
}
