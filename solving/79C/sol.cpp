/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 03:48:58 PM IST
(ツ) Let your hook always be cast; in the pool where you least expect it, there will be a fish.
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

const int N = 1e5 + 5, inf = 1e18;

int n;
int bestUpto[N];

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
			RMQ[0][i] = bestUpto[i];	   // leaf value
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
} T;

int getMin(int L, int R) {
	assert(L <= R);
	return T.query(L, R);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	s = "@" + s;
	int m;
	cin >> m;

	vector<string> strs(m);
	for (auto& str : strs)
		cin >> str;

	n = s.size() - 1;

	for (int i = 1; i <= n; i++) {
		bestUpto[i] = inf;
		for (int j = 0; j < m; j++) {
			int len = sz(strs[j]);
			if (i + len - 1 > n)
				continue;
			bool keep = true;
			for (int k = 0; k < len; k++)
				keep &= s[i + k] == strs[j][k];
			if (keep)
				bestUpto[i] = min(bestUpto[i], i + len - 1);
		}
	}

	T.precompute(n);

	int bestLen = 0, start = 0;

	FOR(i, 1, n) {
		int L = i;
		int R = -1;
		// finding the best R
		int lo = i, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int worst = getMin(L, mid);
			assert(worst >= L);
			if (worst > mid)
				R = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		if (~R)
			if (bestLen < R - L + 1)
				bestLen = R - L + 1, start = L - 1;
	}

	cout << bestLen << " " << start << "\n";
}
