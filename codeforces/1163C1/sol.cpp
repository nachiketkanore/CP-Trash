/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 10 February 2024 12:08:10 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<pair<int, int>> pts(N);
	for (auto& [x, y] : pts) {
		cin >> x >> y;
	}
	sort(ALL(pts));
	set<int> vertical, horizontal;
	set<array<int, 3>> others;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];
			if (x1 == x2) {
				vertical.insert(x1);
			} else if (y1 == y2) {
				horizontal.insert(y1);
			} else {
				int A = y2 - y1, B = x2 - x1;

				int a = A, b = -B, c = B * y1 - A * x1;
				int g = __gcd(abs(a), __gcd(abs(b), abs(c)));
				a /= g, b /= g, c /= g;
				if (a < 0 && b < 0 && c < 0) {
					a = -a, b = -b, c = -c;
				}
				others.insert({ a, b, c });

				// A /= g, B /= g;
				// if (A < 0 && B < 0)
				// 	A = -A, B = -B;
				// else if (A > 0 && B < 0)
				// 	A = -A, B = -B;
			}
		}
	}
	// see(vertical);
	// see(horizontal);
	// see(others);

	int v = sz(vertical), h = sz(horizontal), o = sz(others);
	int ans = 0;

	ans += v * h;
	ans += v * o;
	ans += h * o;
	ans += o * (o - 1) / 2;

	cout << ans;

	return 0;
}
