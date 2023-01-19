/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:03:30 PM IST
(ツ) Let the future tell the truth, and evaluate each one according to his work and accomplishments. The present is theirs; the future, for which I have really worked, is mine.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int val[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int sum = 0;
		FOR(i, 0, n + 5) val[i] = 0;
		FOR(i, 1, n) {
			cin >> val[i];
			sum += val[i];
		}

		vector<pair<int, int>> segs;

		for (int i = 1; i <= n; i++) {
			if (val[i]) {
				int j = i;
				while (j <= n && val[j] == 1)
					j++;
				j--;
				segs.push_back({ i, j });
				i = j;
			}
		}

		// for (auto it : segs) cout << it.first << ' ' << it.second << '\n';	cout << '\n';

		int ans = inf;
		if (sum == 0)
			ans = 0;

		for (int i = 0; i < sz(segs); i++) {
			int cost = 0;
			for (int j = i - 1; j >= 0; j--) {
				cost += segs[j + 1].first - segs[j].second - 1;
			}
			for (int j = i + 1; j < sz(segs); j++) {
				cost += segs[j].first - segs[j - 1].second - 1;
			}
			ans = min(ans, cost);
		}

		cout << ans << '\n';
	}
}
