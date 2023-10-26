/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 11:54:20 AM IST
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

const int INF = 1e18;

void solve() {
	int N, H;
	cin >> N >> H;
	vector<int> A(N);

	int SUM = 0;
	for (int& x : A) {
		cin >> x;
		SUM += x;
	}

	auto check = [&](int k) {
		int D = 0;
		for (int x : A) {
			D += (x / k) * (x / k);
			if (D > SUM)
				break;
		}
		// SUM / D >= H
		// return SUM >= H * D;
		if (D == 0) {
			return true;
		}

		__int128_t product = __int128_t(H) * __int128_t(D);
		__int128_t sum = __int128_t(SUM);

		return __int128_t(SUM) / __int128_t(D) >= __int128_t(H);
	};

	int lo = 1, hi = INF;
	int answer = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			answer = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << answer << '\n';
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
