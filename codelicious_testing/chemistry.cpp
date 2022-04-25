/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 April 2022 05:08:07 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct pt {
	double x, y;
	int cost;
};

int orientation(pt a, pt b, pt c) {
	double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	if (v < 0)
		return -1; // clockwise
	if (v > 0)
		return +1; // counter-clockwise
	return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
	int o = orientation(a, b, c);
	return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
	if (a.size() == 1)
		return;

	sort(a.begin(), a.end(),
	[](pt a, pt b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); });
	pt p1 = a[0], p2 = a.back();
	vector<pt> up, down;
	up.push_back(p1);
	down.push_back(p1);
	for (int i = 1; i < (int)a.size(); i++) {
		if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
			while (up.size() >= 2 &&
			!cw(up[up.size() - 2], up[up.size() - 1], a[i], include_collinear))
				up.pop_back();
			up.push_back(a[i]);
		}
		if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
			while (down.size() >= 2 &&
			!ccw(down[down.size() - 2], down[down.size() - 1], a[i], include_collinear))
				down.pop_back();
			down.push_back(a[i]);
		}
	}

	if (include_collinear && up.size() == a.size()) {
		reverse(a.begin(), a.end());
		return;
	}
	a.clear();
	for (int i = 0; i < (int)up.size(); i++)
		a.push_back(up[i]);
	for (int i = down.size() - 2; i > 0; i--)
		a.push_back(down[i]);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	assert(1 <= N && N <= 200000);
	vector<pt> A(N);
	for (auto& it : A) {
		cin >> it.x >> it.y >> it.cost;
		assert(1 <= it.x && it.x <= 200000);
		assert(1 <= it.y && it.y <= 200000);
		assert(1 <= it.cost && it.cost <= 200000);
		assert(it.x + it.y != 0);
	}
	convex_hull(A);
	int ans = 0;
	for (auto& it : A) {
		ans += it.cost;
	}
	cout << ans << '\n';
	return 0;
}
