/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 31 May 2022 12:51:55 PM IST
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

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {
	}
	bool operator<(const Point& other) {
		return make_pair(x, y) < make_pair(other.x, other.y);
	}
};

ostream& operator<<(std::ostream& os, const Point& pt) {
	os << "[" << pt.x << ", " << pt.y << "]\n";
	return os;
}

struct Level {
	int level;
	vector<Point> horizontal, vertical;
	int x1, y1, x2, y2;
	int path_len;

	Level(int level, const vector<Point>& pts) : level(level) {
		for (Point pt : pts) {
			if (pt.x == level) {
				vertical.push_back(pt);
			}
			if (pt.y == level) {
				horizontal.push_back(pt);
			}
			if (pt.x != level && pt.y != level) {
				assert(false);
			}
		}
		sort(ALL(vertical));
		sort(ALL(horizontal));

		if (!vertical.empty()) {
			x1 = vertical[0].x, y1 = vertical[0].y;
		} else {
			x1 = horizontal.back().x, y1 = horizontal.back().y;
		}
		if (!horizontal.empty()) {
			x2 = horizontal[0].x, y2 = horizontal[0].y;
		} else {
			x2 = vertical.back().x, y2 = vertical.back().y;
		}

		path_len = abs(x1 - x2) + abs(y1 - y2);
	}

	bool operator<(const Level& other) {
		return level < other.level;
	}
};

const int INF = 1e18;
const int _ = 5e5 + 5;
int N, M;
map<int, vector<Point>> pts;
vector<Level> levels;
int dp[2][_];

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int go(int id, int where) {
	if (id == M - 1) {
		return levels[id].path_len;
	}

	int& ans = dp[where][id];
	if (~ans)
		return ans;
	ans = INF;

	if (where == 0) {
		int cost = levels[id].path_len;
		int cx = levels[id].x1, cy = levels[id].y1;
		int nx1 = levels[id + 1].x1, ny1 = levels[id + 1].y1;
		int nx2 = levels[id + 1].x2, ny2 = levels[id + 1].y2;
		int gx = levels[id].x2, gy = levels[id].y2;

		int c1 = cost + dist(gx, gy, nx1, ny1) + go(id + 1, 0);
		int c2 = cost + dist(gx, gy, nx2, ny2) + go(id + 1, 1);

		ans = min(c1, c2);
	} else if (where == 1) {
		int cost = levels[id].path_len;
		int cx = levels[id].x2, cy = levels[id].y2;
		int nx1 = levels[id + 1].x1, ny1 = levels[id + 1].y1;
		int nx2 = levels[id + 1].x2, ny2 = levels[id + 1].y2;
		int gx = levels[id].x1, gy = levels[id].y1;

		int c1 = cost + dist(gx, gy, nx1, ny1) + go(id + 1, 0);
		int c2 = cost + dist(gx, gy, nx2, ny2) + go(id + 1, 1);

		ans = min(c1, c2);
	} else {
		assert(false);
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> N;
	F0R(i, N) {
		int x, y;
		cin >> x >> y;
		pts[max(x, y)].push_back(Point(x, y));
	}

	for (const auto& [level, points] : pts) {
		levels.push_back(Level(level, points));
	}
	sort(ALL(levels));

	M = levels.size();

	int ans = dist(0, 0, levels[0].x1, levels[0].y1) + go(0, 0);
	ans = min(ans, dist(0, 0, levels[0].x2, levels[0].y2) + go(0, 1));

	cout << ans << '\n';

	return 0;
}
