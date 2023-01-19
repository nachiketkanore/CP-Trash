/*
Author: Nachiket Kanore
Created: Sunday 10 January 2021 06:23:36 PM IST
(ツ) Transformation doesn't take place with a vacuum; instead, it occurs when we are indirectly and directly connected to all those around us.
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
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int m;
	cin >> m;

	vector<set<int>> g(n);

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].insert(v);
		g[v].insert(u);
	}

	int ans = 0;

	while (1) {
		bool found = false;

		using pii = pair<int, int>;
		set<pii> to_remove;
		for (int i = 0; i < n; i++) {
			if (sz(g[i]) == 1) {
				found = true;
				int u = i;
				int v = *g[i].begin();
				if (u > v)
					swap(u, v);
				to_remove.insert({ u, v });
			}
		}
		if (found) {
			++ans;
			for (auto it : to_remove) {
				int u = it.first;
				int v = it.second;
				g[u].erase(g[u].find(v));
				g[v].erase(g[v].find(u));
			}
		} else
			break;
	}

	cout << ans << '\n';
}
