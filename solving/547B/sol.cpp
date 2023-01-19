/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 07:15:44 PM IST
(ツ) He who knows others is wise. He who knows himself is enlightened.
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

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 2e9;

int n, a[N], keep[N];

// can be used for Range min/max/gcd range query in O(1)
class sparseTable {
	public:
	int RMQ[20][N];
	int floorlog[N];

	void precompute(int n) {
		for (int i = 0; (1 << i) < N; i++) {
			for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++)
				floorlog[j] = i;
		}

		for (int i = n; i >= 1; i--) {
			RMQ[0][i] = a[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = min(RMQ[j - 1][i], RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];					 // 2^k <= R-L+1
		return min(RMQ[k][L], RMQ[k][R - (1 << k) + 1]); // operation
	}

	int getMin(int L, int R) {
		return query(L, R);
	}
} T;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	T.precompute(n);

	FOR(i, 1, n) {
		// This is my min value for what sizes of groups ?
		// Finding right border
		int lo = i, hi = n;
		int right = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (T.getMin(i, mid) == a[i]) {
				right = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		assert(~right);

		// Finding left border
		lo = 1, hi = i;
		int left = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (T.getMin(mid, i) == a[i]) {
				left = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		assert(~left);
		assert(left <= right);

		int tot = right - left + 1;
		keep[tot] = max(keep[tot], a[i]);
	}

	int currMax = -inf;
	for (int i = n; i >= 1; i--) {
		currMax = max(currMax, keep[i]);
		keep[i] = currMax;
	}
	FOR(i, 1, n) {
		cout << keep[i] << " \n"[i == n];
	}
}