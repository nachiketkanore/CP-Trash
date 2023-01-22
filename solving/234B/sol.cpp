/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 07:16:57 PM IST
(ツ) Learn to listen. Opportunity could be knocking at your door very softly.
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

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a;
	FOR(i, 1, n) {
		int u;
		cin >> u;
		a.push_back({ u, i });
	}
	sort(a.begin(), a.end());
	int ans = inf;
	FOR(i, 1, k) ans = min(ans, a[n - i].first);
	cout << ans << "\n";
	while (k--) {
		cout << a.back().second << " \n"[k == 0];
		a.pop_back();
	}
}
