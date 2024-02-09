/**
 *    Author: Nachiket Kanore
 *    Created: Friday 09 February 2024 06:24:41 PM IST
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
	map<int, int> freq;
	F0R(i, N) {
		int u;
		cin >> u;
		++freq[u];
	}
	vector<int> counts;
	for (auto [_, v] : freq) {
		counts.push_back(v);
	}
	sort(ALL(counts));
	int ans = 0;
	FOR(first, 1, N) {
		int get = 0, ask = first;
		int from_id = 0;
		while (true) {
			int id = lower_bound(counts.begin() + from_id, counts.end(), ask) - counts.begin();
			if (id < sz(counts)) {
				get += ask;
				ask <<= 1;
				from_id = id + 1;
			} else {
				break;
			}
		}
		ans = max(ans, get);
	}
	cout << ans << '\n';

	return 0;
}
