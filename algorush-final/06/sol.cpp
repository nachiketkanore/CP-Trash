/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 01:43:08 PM IST
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

int info[50][50];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// finding patterns

	auto add_vals = [](int u) {
		vector<pair<int, int>> ret;
		assert(u > 1);
		for (int val = 1; val < u; val++) {
			ret.push_back(make_pair(val, u - val));
		}
		return ret;
	};

	vector<vector<int>> pre;

	FOR(N, 2, 15) {
		vector<pair<int, int>> curr;
		FOR(val, 1, N - 1) {
			curr.push_back(make_pair(val, N - val));
		}
		vector<int> add;
		add.push_back(1);
		add.push_back(sz(curr));
		/* info[N][0] = 1;
		info[N][1] = sz(curr); */

		FOR(lvl, 2, N - 1) {
			vector<pair<int, int>> nxt;
			for (auto [x, y] : curr) {
				for (int chk : { x, y }) {
					if (chk > 1) {
						auto add = add_vals(chk);
						for (auto it : add) {
							nxt.push_back(it);
						}
					}
				}
			}
			curr = nxt;
			// info[N][lvl] = sz(curr);
			add.push_back(sz(curr));
		}

		pre.push_back(add);
	}

	F0R(N, sz(pre)) {
		see(N + 2, ": ", pre[N]);
	}

	return 0;
}
