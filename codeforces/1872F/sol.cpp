/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 12:02:24 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N;
	cin >> N;
	vector<int> A(N + 1), C(N + 1), vis(N + 1), ans;
	vector<bool> in_cycle(N + 1);
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, N) cin >> C[i];

	vector<vector<int>> cycles;
	set<int> done;

	FOR(a, 1, N) {
		int start = a;
		int cycle_start = -1;
		set<int> vis;
		vector<int> path;
		while (true) {
			if (done.count(start))
				break;
			vis.insert(start);
			path.push_back(start);
			int nxt = A[start];
			if (vis.count(nxt)) {
				cycle_start = nxt;
				break;
			} else {
				start = nxt;
			}
		}
		if (~cycle_start) {
			int id = find(ALL(path), cycle_start) - path.begin();
			vector<int> cycle;
			FOR(j, id, sz(path) - 1) {
				cycle.push_back(path[j]);
				in_cycle[path[j]] = true;
			}
			cycles.push_back(cycle);
		}
		for (int x : path) {
			done.insert(x);
		}
	}
	vector<int> indegree(N + 1);
	FOR(i, 1, N) if (!in_cycle[i]) {
		indegree[A[i]]++;
	}
	queue<int> start;
	FOR(i, 1, N) if (!in_cycle[i]) {
		if (indegree[i] == 0) {
			start.push(i);
		}
	}

	while (!start.empty()) {
		int curr = start.front();
		start.pop();
		assert(indegree[curr] == 0 && !in_cycle[curr]);
		ans.push_back(curr);
		indegree[A[curr]]--;
		if (!in_cycle[A[curr]] && indegree[A[curr]] == 0) {
			start.push(A[curr]);
		}
	}

	for (auto cycle : cycles) {
		int id = 0, mn = C[cycle[0]];
		F0R(j, sz(cycle)) {
			if (C[cycle[j]] < mn) {
				mn = C[cycle[j]];
				id = j;
			}
		}
		FOR(j, id + 1, sz(cycle) - 1) ans.push_back(cycle[j]);
		F0R(j, id + 1) ans.push_back(cycle[j]);
	}

	assert(sz(ans) == N);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
