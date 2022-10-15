/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 15 October 2022 06:58:53 PM IST
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
	int rs, rh;
	cin >> rs >> rh;
	vector<pair<int, int>> red, yellow;
	int N;
	cin >> N;
	F0R(i, N) {
		int x, y;
		cin >> x >> y;
		red.push_back(make_pair(x, y));
	}
	int M;
	cin >> M;
	F0R(i, M) {
		int x, y;
		cin >> x >> y;
		yellow.push_back(make_pair(x, y));
	}

	auto outside = [&](int x, int y) { return (rh + rs) * (rh + rs) < x * x + y * y; };

	int ansred = 0;
	F0R(i, N) {
		auto [x, y] = red[i];
		if (outside(x, y))
			continue;
		// see("red inside: ", x, y);
		bool bad = false;
		F0R(j, M) {
			auto [x1, y1] = yellow[j];
			if (outside(x1, y1))
				continue;
			bad |= x1 * x1 + y1 * y1 < x * x + y * y;
		}
		if (!bad)
			++ansred;
	}

	int ansyellow = 0;
	F0R(i, M) {
		auto [x, y] = yellow[i];
		if (outside(x, y))
			continue;
		bool bad = false;
		F0R(j, N) {
			auto [x1, y1] = red[j];
			if (outside(x1, y1))
				continue;
			bad |= x1 * x1 + y1 * y1 < x * x + y * y;
		}
		if (!bad)
			++ansyellow;
	}

	cout << ansred << ' ' << ansyellow << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
