/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 September 2021 01:26:12 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int _ = 3003;
vector<int> g[_];
set<array<int, 3>> bad;

struct state {
	int dist, curr, prev;
	state(int dist, int curr, int prev) : dist(dist), curr(curr), prev(prev) {
	}
};

set<pair<int, int>> vis;
map<pair<int, int>, pair<int, int>> prev_state;

int32_t main() {
	int N, M, K;
	cin >> N >> M >> K;
	FOR(i, 1, M) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	FOR(i, 1, K) {
		int a, b, c;
		cin >> a >> b >> c;
		bad.insert({ a, b, c });
	}
	queue<state> Q;
	Q.push(state(0, 1, 0));

	while (!Q.empty()) {
		state U = Q.front();
		Q.pop();

		int u = U.curr, dist = U.dist, prev = U.prev;
		if (u == N) {
			cout << dist << '\n';
			// trace
			vector<int> ans;
			while (true) {
				ans.push_back(u);
				auto last = prev_state[make_pair(prev, u)];
				u = last.second;
				prev = last.first;
				if (u == 0 || prev == 0)
					break;
			}
			if (sz(ans) && ans.back() != 1)
				ans.push_back(1);
			reverse(ALL(ans));
			for (int x : ans) {
				cout << x << ' ';
			}
			cout << '\n';
			return 0;
		}

		for (int v : g[u]) {
			array<int, 3> path = { prev, u, v };
			if (bad.count(path))
				continue;
			if (vis.count({ u, v }))
				continue;
			vis.insert({ u, v });
			prev_state[make_pair(u, v)] = make_pair(prev, u);
			Q.push(state(dist + 1, v, u));
		}
	}
	cout << "-1\n";
}
