/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 May 2022 12:59:46 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
const int INF = 1e15;
int N;
pair<int, int> up[_], down[_];

int manhattan_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int manhattan_distance(int x1, int y1, pair<int, int> other) {
	return abs(x1 - other.first) + abs(y1 - other.second);
}

int dp[2][_];

int go(int curr_level, int curr_door, int final_level, int final_door) {
	assert(curr_level <= final_level);
	if (curr_level == final_level) {
		if (curr_door == final_door)
			return 0;
		return INF;
	}

	int& ans = dp[curr_door][curr_level];
	if (~ans)
		return ans;
	ans = INF;

	if (curr_door == 0) {
		// up door <-- current position
		int x = up[curr_level].first, y = up[curr_level].second;

		int nx0 = up[curr_level + 1].first, ny0 = up[curr_level + 1].second;
		int nx1 = down[curr_level + 1].first, ny1 = down[curr_level + 1].second;

		int c1 = 1 + manhattan_distance(x + 1, y, nx0, ny0) + go(curr_level + 1, 0, final_level, final_door);

		int c2 = 1 + manhattan_distance(x + 1, y, nx1, ny1) + go(curr_level + 1, 1, final_level, final_door);

		ans = min(ans, c1);
		ans = min(ans, c2);
	} else if (curr_door == 1) {
		// down door <-- current position
		int x = down[curr_level].first, y = down[curr_level].second;

		int nx0 = up[curr_level + 1].first, ny0 = up[curr_level + 1].second;
		int nx1 = down[curr_level + 1].first, ny1 = down[curr_level + 1].second;

		int c1 = 1 + manhattan_distance(x, y + 1, nx0, ny0) + go(curr_level + 1, 0, final_level, final_door);

		int c2 = 1 + manhattan_distance(x, y + 1, nx1, ny1) + go(curr_level + 1, 1, final_level, final_door);

		ans = min(ans, c1);
		ans = min(ans, c2);
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// not optimal

	cin >> N;
	FOR(level, 1, N - 1) {
		cin >> up[level].first >> up[level].second;
		cin >> down[level].first >> down[level].second;
	}

	auto get_level = [&](int x, int y) { return max(x, y); };

	int Q;
	cin >> Q;
	while (Q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int level1 = get_level(x1, y1), level2 = get_level(x2, y2);

		if (level1 == level2) {
			// same level --> no door traversal
			cout << manhattan_distance(x1, y1, x2, y2) << '\n';
		} else {
			// go from lower level to higher
			// level1 to level2
			if (level1 > level2) {
				swap(x1, x2);
				swap(y1, y2);
				swap(level1, level2);
			}

			auto reset_dp = [&]() { FOR(i, level1, level2) F0R(j, 2) dp[j][i] = -1; };

			reset_dp();
			int cost00 = go(level1, 0, level2 - 1, 0);
			reset_dp();
			int cost01 = go(level1, 0, level2 - 1, 1);
			reset_dp();
			int cost10 = go(level1, 1, level2 - 1, 0);
			reset_dp();
			int cost11 = go(level1, 1, level2 - 1, 1);

			int best = INF;

			int c00 = manhattan_distance(x1, y1, up[level1]) + cost00 + 1 + manhattan_distance(up[level2 - 1].first + 1, up[level2 - 1].second, x2, y2);

			int c01 = manhattan_distance(x1, y1, up[level1]) + cost01 + 1 + manhattan_distance(down[level2 - 1].first, down[level2 - 1].second + 1, x2, y2);

			int c10 = manhattan_distance(x1, y1, down[level1]) + cost10 + 1 + manhattan_distance(up[level2 - 1].first + 1, up[level2 - 1].second, x2, y2);

			int c11 = manhattan_distance(x1, y1, down[level1]) + cost11 + 1 + manhattan_distance(down[level2 - 1].first, down[level2 - 1].second + 1, x2, y2);

			best = min({ c00, c01, c10, c11 });
			assert(best ^ INF);
			cout << best << '\n';
		}
	}

	return 0;
}
