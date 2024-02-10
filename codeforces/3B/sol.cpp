/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 10 February 2024 10:39:37 AM IST
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

	int N, V;
	cin >> N >> V;
	vector<pair<int, int>> one, two;
	FOR(i, 1, N) {
		int t, p;
		cin >> t >> p;
		if (t == 1)
			one.push_back({ p, i });
		else
			two.push_back({ p, i });
	}
	sort(ALL(one));
	reverse(ALL(one));
	FOR(i, 1, sz(one) - 1) one[i].first += one[i - 1].first;
	sort(ALL(two));
	reverse(ALL(two));
	FOR(i, 1, sz(two) - 1) two[i].first += two[i - 1].first;

	int ans = -1, take_c1 = 0, take_c2 = 0;

	FOR(c2, 0, sz(two)) {
		if (V - c2 * 2 < 0)
			continue;
		int c1 = V - c2 * 2;
		c1 = min(c1, sz(one));
		int get = (c1 ? one[c1 - 1].first : 0) + (c2 ? two[c2 - 1].first : 0);
		if (get > ans) {
			ans = get;
			take_c1 = c1;
			take_c2 = c2;
		}
	}
	cout << ans << '\n';
	vector<int> choices;
	F0R(id, take_c1) choices.push_back(one[id].second);
	F0R(id, take_c2) choices.push_back(two[id].second);
	sort(ALL(choices));
	for (int c : choices) {
		cout << c << ' ';
	}
	return 0;
}
