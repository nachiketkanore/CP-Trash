/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 08:49:59 PM IST
(ツ) Genuine sincerity opens people's hearts, while manipulation causes them to close.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 3e5 + 5, inf = 1e18;

int n, a[N];
int pref[N], suff[N];
int floorlog[N + 5];

void precompute() {
	for (int i = 0; (1 << i) < N; i++) {
		for (int j = (1 << i); j < N && j < (1 << (i + 1)); j++) {
			floorlog[j] = i;
		}
	}
}

// can be used for Range min/max/gcd range query in O(1)
class sparseTable {
	public:
	vector<int> RMnQ[20];
	vector<int> RMxQ[20];

	void init(int n) {
		for (int i = 0; i < 20; i++)
			RMnQ[i] = vector<int>(n + 2, 0), RMxQ[i] = vector<int>(n + 2, 0);

		for (int i = n; i >= 1; i--) {
			RMnQ[0][i] = RMxQ[0][i] = a[i]; // leaf value
			int mxj = floorlog[n - i + 1];	// 2^j <= n-i+1
			int pw = 1;
			for (int j = 1; j <= mxj; j++) {
				RMnQ[j][i] = min(RMnQ[j - 1][i], RMnQ[j - 1][i + pw]); // operation
				RMxQ[j][i] = max(RMxQ[j - 1][i], RMxQ[j - 1][i + pw]); // operation
				pw <<= 1;
			}
		}
	}

	int getMin(int L, int R) {
		int k = floorlog[R - L + 1];					   // 2^k <= R-L+1
		return min(RMnQ[k][L], RMnQ[k][R - (1 << k) + 1]); // operation
	}

	int getMax(int L, int R) {
		int k = floorlog[R - L + 1];					   // 2^k <= R-L+1
		return max(RMxQ[k][L], RMxQ[k][R - (1 << k) + 1]); // operation
	}
} T;

int getMin(int L, int R) {
	if (L > R)
		return inf;
	return T.getMin(L, R);
}

int getMax(int L, int R) {
	if (L > R)
		return -inf;
	return T.getMax(L, R);
}

void solve() {
	cin >> n;
	map<int, vector<int>> pos;
	FOR(i, 1, n) {
		cin >> a[i];
		pref[i] = a[i];
		pref[i] = max(pref[i - 1], pref[i]);
		suff[i] = a[i];
	}
	for (int i = n; i >= 1; i--) {
		if (i != n)
			suff[i] = max(suff[i], suff[i + 1]);
		pos[suff[i]].push_back(i);
	}

	T.init(n);
	for (auto& it : pos)
		sort(it.second.begin(), it.second.end());

	FOR(i, 1, n) {
		int left = pref[i];
		if (!pos.count(left))
			continue;
		vector<int>& ids = pos[left];

		int L = upper_bound(ids.begin(), ids.end(), i) - ids.begin();
		if (L == sz(ids))
			continue;
		L = ids[L];
		int R = ids.back();

		assert(i < L && L <= R);

		// binary search to find an element in monotonic sequence
		int lo = L - 1, hi = R - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			assert(getMax(mid + 1, n) == left);

			if (left == getMin(i + 1, mid)) {
				cout << "YES\n";
				cout << i << " " << (mid - i) << " " << (n - mid) << "\n";
				return;
			} else if (left > getMin(i + 1, mid)) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
	}

	cout << "NO\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	precompute();
	int T;
	cin >> T;
	while (T--)
		solve();
}
