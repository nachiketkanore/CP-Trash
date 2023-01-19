/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:03:35 PM IST
(ツ) The first duty of a human being is to assume the right functional relationship to society more briefly, to find your real job, and do it.
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

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 5000 + 5, inf = 1e9;

int n, a[N];

int par[N];

int find(int u) {
	if (par[u] == u)
		return u;
	par[u] = find(par[par[u]]);
	return u = par[u];
}

bool unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v)
		return false;
	par[u] = v;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 1, n) {
			cin >> a[i];
			par[i] = i;
		}

		vector<pair<int, int>> all, ans;

		FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] != a[j]) {
			all.push_back({ i, j });
		}

		for (auto [L, R] : all) {
			if (unite(L, R)) {
				ans.push_back({ L, R });
			}
		}

		int who = find(1);
		bool same = true;

		FOR(i, 1, n) same &= find(i) == who;

		if (same) {
			cout << "YES\n";
			assert(sz(ans) == n - 1);
			for (auto [L, R] : ans) {
				cout << L << " " << R << "\n";
			}
		} else
			cout << "NO\n";

		ans.clear();
		all.clear();
	}
}
