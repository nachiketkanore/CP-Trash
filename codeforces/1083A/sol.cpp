/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Friday 09 February 2024 06:56:23 PM IST
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

const int MAX = 3e5 + 5;
int N, W[MAX], dp_down[MAX], answer;
vector<pair<int, int>> G[MAX];

int go_down(int u, int par) {
	int best = W[u];
	for (auto [v, w] : G[u]) {
		if (v ^ par) {
			int get = -w + go_down(v, u);
			best = max(best, W[u] + get);
		}
	}
	return dp_down[u] = best;
}

void go_combine(int u, int par) {
	int best = dp_down[u];
	vector<int> child_ans;

	for (auto [v, w] : G[u]) {
		if (v ^ par) {
			child_ans.push_back(dp_down[v] + -w);
		}
	}
	sort(ALL(child_ans));
	reverse(ALL(child_ans));
	if (sz(child_ans) >= 2) {
		best = max(best, W[u] + child_ans[0] + child_ans[1]);
	} else if (sz(child_ans) == 1) {
		best = max(best, W[u] + child_ans[0]);
	}

	answer = max(answer, best);

	for (auto [v, w] : G[u]) {
		if (v ^ par) {
			go_combine(v, u);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	FOR(i, 1, N) cin >> W[i];
	F0R(i, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({ v, w });
		G[v].push_back({ u, w });
	}

	go_down(1, 1);
	go_combine(1, 1);

	cout << answer << '\n';

	return 0;
}
