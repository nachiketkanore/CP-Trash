/*
Author: Nachiket Kanore
Created: Sunday 22 November 2020 05:25:17 PM IST
(ツ) As we express our gratitude, we must never forget that the highest appreciation is not to utter words, but to live by them.
*/
#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)

using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, T;
	cin >> n >> T;

	vector<int> a(n), one, two, vals1, vals2;
	for (int &x : a) cin >> x;

	FOR (i,1,n) {
		if (i <= 20) {
			one.push_back(a[i-1]);
		} else {
			two.push_back(a[i-1]);
		}
	}

	for (int mask = 0; mask < (1 << sz(one)); mask++) {
		int sum = 0;
		for (int i = 0; i < sz(one); i++)
			if (mask >> i & 1)
				sum += one[i];
		vals1.push_back(sum);
	}

	for (int mask = 0; mask < (1 << sz(two)); mask++) {
		int sum = 0;
		for (int i = 0; i < sz(two); i++)
			if (mask >> i & 1)
				sum += two[i];
		vals2.push_back(sum);
	}

	sort(vals1.begin(), vals1.end());
	sort(vals2.begin(), vals2.end());

	int ans = 0;

	for (int x : vals1) if (x <= T) ans = max(ans, x);
	for (int x : vals2) if (x <= T) ans = max(ans, x);

	for (int x : vals1) if (x <= T) {
		int y = T - x;
		int id = -1;

		int lo = 0, hi = sz(vals2)-1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (vals2[mid] <= y) id = mid, lo = mid+1;
			else hi = mid-1;
		}
		if (~id) {
			assert(vals2[id] <= y);
			y = vals2[id];
			assert(x + y <= T);
			ans = max(ans, x + y);
		}
	}
	cout << ans;
}
