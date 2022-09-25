/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 September 2022 08:10:06 PM IST
**/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N; cin >> N;
	vector<pair<int,int>> A(N);
	for (auto &it: A) { cin >> it.first; }
	for (auto &it: A) { cin >> it.second; }

	auto f = [&](double x0) {
		double ans = -1e18;
		for (const auto &[x, t]: A) {
			ans = max(ans, t + abs((double)x - x0));
		}
		return ans;
	};

	double l = 0, r = 1e9;
	const double eps = 1e-6;
	while (r - l > eps) {
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		double f1 = f(m1);
		double f2 = f(m2);
		if (f1 > f2) {
			l = m1;
		} else {
			r = m2;
		}
	}

	cout << fixed << setprecision(15) << l << '\n';
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
