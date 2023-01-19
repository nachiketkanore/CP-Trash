/*
Author: Nachiket Kanore
Created: Thursday 31 December 2020 05:51:46 PM IST
(ツ) If you spend your whole life waiting for the storm, you'll never enjoy the sunshine.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 1e5 + 5, inf = 1e9;

int n;
int arr[N];

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
			RMQ[0][i] = arr[i];			   // leaf value
			int mxj = floorlog[n - i + 1]; // 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMQ[j][i] = (RMQ[j - 1][i] | RMQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int query(int L, int R) {
		int k = floorlog[R - L + 1];				   // 2^k <= R-L+1
		return (RMQ[k][L] | RMQ[k][R - (1 << k) + 1]); // operation
	}
} T;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	T.precompute(n);

	set<int> possible;

	for (int L = 1; L <= n; L++) {
		int from = L;

		while (from <= n) {
			int want = T.query(L, from);
			possible.insert(want);
			int nxt = -1;

			int lo = from, hi = n;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				int rangeOR = T.query(L, mid);
				if (rangeOR == want) {
					nxt = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			assert(~nxt);
			from = nxt + 1;
		}
	}

	cout << sz(possible) << '\n';
}
