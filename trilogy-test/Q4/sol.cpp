/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 06 August 2023 03:36:50 PM IST
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

	map<int, int> deltas;

	int N;
	cin >> N;
	F0R(i, N) {
		int L, R;
		cin >> L >> R;
		deltas[L] += 1;
		deltas[R + 1] -= 1;
	}
	vector<pair<int, int>> chk;
	for (auto [pos, delta] : deltas) {
		chk.push_back({ pos, delta });
	}
	sort(ALL(chk));

	vector<int> ans(N + 1);
	int last = -1, cnt = 0;

	for (auto [pos, delta] : chk) {
		if (delta <= 0) {
			int points = pos - last;
			ans[cnt] += points;
		} else {
			if (~last) {
				int points = pos - last;
				ans[cnt] += points;
			}
		}
		cnt += delta;
		last = pos;
	}
	ans[0] = 0;

	for (auto x : ans) {
		cout << x << ' ';
	}

	return 0;
}
