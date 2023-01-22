/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 02:15:31 PM IST
(ツ) Take rest; a field that has rested gives a bountiful crop.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

struct FenwickTree {
	vector<int> bit; // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}

	void addOnRange(int L, int R, int val) {
		add(L, val);
		add(R + 1, -val);
	}
} tree(N + 5);

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n = 1, sum = 0;
	cin >> t;

	FOR(i, 1, t) {
		int type;
		cin >> type;

		if (type == 1) {
			int cnt, val;
			cin >> cnt >> val;
			tree.addOnRange(1, cnt, val);
			sum += cnt * val;
		} else if (type == 2) {
			int last;
			cin >> last;
			n++;
			tree.addOnRange(n, n, last);
			sum += last;
		} else {
			int cnt = tree.sum(n);
			sum -= cnt;
			tree.addOnRange(n, n, -cnt);
			n--;
		}

		cout << fixed << setprecision(10) << 1.0 * sum / n << "\n";
	}
}
