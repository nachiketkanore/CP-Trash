/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:04:43 PM IST
(ツ) Always be yourself, express yourself, have faith in yourself, do not go out and look for a successful personality and duplicate it.
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

int a[N];
std::vector<int> pos[N];

void solve() {
	int n;
	cin >> n;
	FOR(i, 0, n + 2) a[i] = 0, pos[i].clear();
	FOR(i, 1, n) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}

	int ans = inf;

	FOR(val, 1, n) {
		std::vector<int>& chk = pos[val];
		if (chk.empty())
			continue;
		if (sz(chk) == 1) {
			int x = chk.back();
			int left = x - 1, right = n - x;
			int get = (left > 0) + (right > 0);
			ans = min(ans, get);
			// cerr << val << " " << get << "\n";
			continue;
		}
		int left = chk.front() - 1;
		int get = (left > 0);
		for (int i = 1; i < sz(chk); i++) {
			get += (chk[i] - chk[i - 1]) > 1;
		}
		int right = n - chk.back();
		get += (right > 0);
		// cerr << val << " " << get << "\n";
		ans = min(ans, get);
	}

	assert(ans != inf);
	cout << ans << "\n";
	// exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
