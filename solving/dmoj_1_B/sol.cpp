/*
Author: Nachiket Kanore
Created: Monday 07 December 2020 12:05:34 AM IST
(ツ) Before you put on a frown, make absolutely sure there are no smiles available.
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

const int N = 1e6 + 5, inf = 1e18;

int n, m;
int fi[N], last[N], f[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	fill(fi, fi + N, inf);
	fill(last, last + N, -inf);

	FOR(i, 1, n) {
		int u;
		cin >> u;
		fi[u] = min(fi[u], i);
		last[u] = max(last[u], i);
		f[u] = 1;
	}

	int ans = 0;

	while (m--) {
		int u, v;
		cin >> u >> v;
		if (f[u] && f[v])
			ans = max(ans, last[v] - fi[u] + 1);
	}
	cout << ans;
}
