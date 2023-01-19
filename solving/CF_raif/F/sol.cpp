/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 08:19:30 PM IST
(ツ) Once we accept our limits, we go beyond them.
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

int n, a[N], pref[N], suff[N], ans;

int getMaxPref(int L, int R) {
	int ret = -inf;
	FOR(i, L, R) ret = max(ret, pref[i]);
	return ret;
}

int getMaxSuff(int L, int R) {
	int ret = -inf;
	FOR(i, L, R) ret = max(ret, suff[i]);
	return ret;
}

int get_for_1(int L, int R, int k) {
	int lo = R, hi = n;
	int right = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (getMaxPref(R, mid) <= k) {
			right = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	assert(~right);

	int left = -1;
	lo = 1, hi = L;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (getMaxSuff(mid, L) <= k) {
			left = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	assert(~left);
	assert(left <= L && L <= R && R <= right);

	int add = (L - left + 1) + (right - R + 1) - 1; // check

	return add;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}

	int same = 0;

	FOR(i, 1, n) {
		if (a[i] == 1)
			same++;
		else
			same = 0;
		pref[i] = same;
	}

	same = 0;

	for (int i = n; i >= 1; i--) {
		if (a[i] == 1)
			same++;
		else
			same = 0;
		suff[i] = same;
	}

	vector<pair<int, int>> segs;

	same = 0;
	int left = -1;

	FOR(i, 1, n) {
		if (a[i] == 1) {
			if (left == -1)
				left = i;
			same++;
		} else {
			if (same > 0) {
				assert(~left);
				segs.push_back({ left, i - 1 });
				left = -1;
				same = 0;
			}
		}
	}

	if (same > 0) {
		assert(~left);
		segs.push_back({ left, left + same - 1 });
	}

	for (auto [L, R] : segs) {
		int k = R - L + 1;

		// corner k = 1
		if (k == 1) {
			ans += get_for_1(L, R, k);
			continue;
		}

		// doing for k
		// find right border
		int lo = R, hi = n;
		int right = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (getMaxPref(R, mid) <= k) {
				right = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		assert(~right);

		int left = -1;
		lo = 1, hi = L;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (getMaxSuff(mid, L) <= k) {
				left = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		assert(~left);

		// cout << L << " " << R << " " << left << " " << right << '\n';
		assert(left <= L && L <= R && R <= right);

		int subs = (L - left + 1) * (R - right + 1);
		int add = subs * k;
		ans += add;

		for (int len = k - 1; len >= 1; len--) {
			int l1 = L, r1 = l1 + len - 1;
			int l2 = R - len + 1, r2 = R;
			assert(l1 != l2 && r1 != r2);
			assert(l1 <= r1 && l2 <= r2);

			int internal = (k - len + 1) - 2;
			assert(internal >= 0);
			int add = len * internal;

			int lo = 1, hi = l1 - 1;
			int left = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (getMaxSuff(mid, l1) <= len) {
					left = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}

			if (~left) {
				assert(left <= l1);
				int self_left = (l1 - left + 1) * len;
				add += self_left;
			}

			lo = r2 + 1, hi = n;
			int right = -1;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (getMaxPref(r2, mid) <= len) {
					right = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (~right) {
				assert(right >= r2);
				int self_right = (right - r1 + 1) * len;
				add += self_right;
			}

			ans += add;
		}

		// doing for k - 1, k - 2, ...., 1
	}

	cout << ans << '\n';
}
