#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, m, u, v, w, in[N], out[N];
array<int, 3> edges[N];
bool doneA[N], doneB[N];
multiset<int> taken;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> u >> v >> w;
		edges[i] = { w, u, v };
		in[v]++, out[u]++;
		taken.insert(w);
	}
	sort(edges + 1, edges + m + 1);
	reverse(edges + 1, edges + m + 1);

	bool bad = false;
	FOR(i, 1, n) {
		if (in[i] == 0 || out[i] == 0)
			bad = true;
	}
	if (bad) {
		cout << -1;
		return 0;
	}

	FOR(i, 1, m) {
		int& one = out[edges[i][1]];
		int& two = in[edges[i][2]];
		if (one > 1 && two > 1) {
			one -= 1;
			two -= 1;
			taken.erase(taken.find(edges[i][0]));
		}
	}

	if (bad)
		cout << -1;
	else {
		cout << *taken.rbegin() << '\n';
	}
}