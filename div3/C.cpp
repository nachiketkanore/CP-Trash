/**
 *    Author: Nachiket Kanore
 *    Created: Monday 14 March 2022 07:20:38 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Point {
	int id, x, w;

	Point(int id, int x, int w) : id(id), x(x), w(w) {
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		assert(2 * N <= M);
		vector<Point> pts;
		for (int i = 1; i <= M; i++) {
			int x, w;
			cin >> x >> w;
			pts.push_back(Point(i, x, w));
		}
		sort(pts.begin(), pts.end(), [&](const Point& one, const Point& two) { return one.w < two.w; });
		int cost = 0;
		for (int i = 0; i < 2 * N; i++) {
			cost += pts[i].w;
		}
		cout << cost << '\n';
		sort(pts.begin(), pts.begin() + 2 * N, [&](const Point& one, const Point& two) { return one.x < two.x; });
		int L = 0, R = 2 * N - 1;
		while (L < R) {
			cout << pts[L].id << ' ' << pts[R].id << '\n';
			L++, R--;
		}
	}
	return 0;
}
