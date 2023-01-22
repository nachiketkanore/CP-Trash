/*
Author: Nachiket Kanore
Created: Wednesday 25 November 2020 12:38:17 AM IST
(ツ) Better than a thousand hollow words is one word that brings peace.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n;
	cin >> n;
	int orig;
	orig = n;
	vector<pair<int, int>> pf;
	int which = -1;
	int best = -1;
	for (int d = 2; d * d <= n; d++)
		if (n % d == 0) {
			int cnt = 0;
			while (n % d == 0) {
				++cnt;
				n /= d;
			}
			if (best < cnt) {
				best = cnt;
				which = d;
			}
		}
	if (n > 1)
		if (best < 1) {
			best = 1;
			which = n;
		}
	assert(~best && ~which);
	vector<int> ans;
	while (orig % which == 0) {
		ans.push_back(which);
		orig /= which;
	}
	ans.back() *= orig;
	cout << sz(ans) << "\n";
	for (int x : ans)
		cout << x << " ";
	cout << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
