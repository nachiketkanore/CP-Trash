/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 03:15:10 PM IST
(ツ) Go for it now. The future is promised to no one.
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

const int SZ = 1000;

struct BIT2D {
	int bit[SZ + 1][SZ + 1];
	int n, m;
	BIT2D(int nn, int mn) : n(nn), m(mn) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				bit[i][j] = 0;
	}
	void upd(int X, int Y, int val) {
		bit[X][Y] = val;
	}
	void compute() {
		FOR(i, 1, n) FOR(j, 1, m) bit[i][j] += bit[i][j - 1] + bit[i - 1][j] - bit[i - 1][j - 1];
	}
	int query(int X, int Y) {
		return bit[X][Y];
	}
	int getSum(int R1, int R2, int C1, int C2) {
		int X1 = min(R1, R2);
		int Y1 = min(C1, C2);
		int X2 = max(R1, R2);
		int Y2 = max(C1, C2);
		assert(X1 <= X2 && Y1 <= Y2);
		int ans = query(X2, Y2) - query(X2, Y1 - 1) - query(X1 - 1, Y2) + query(X1 - 1, Y1 - 1);
		return ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, Q;
	cin >> n >> m >> Q;

	BIT2D one(n, m), two(n, m);

	FOR(i, 1, n) FOR(j, 1, m) {
		char ch;
		cin >> ch;
		if (ch == 'M')
			one.upd(i, j, 1);
		else
			two.upd(i, j, 1);
	}

	one.compute();
	two.compute();

	int best1 = 0, best2 = 0;

	// one
	int lo = 1, hi = min(n, m);
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int K = mid;
		bool yes = false;

		FOR(i, 1, n) FOR(j, 1, m) if (i + K - 1 <= n && j + K - 1 <= m) {
			yes |= one.getSum(i, i + K - 1, j, j + K - 1) == K * K;
			if (yes)
				break;
		}
		if (yes)
			best1 = K, lo = mid + 1;
		else
			hi = mid - 1;
	}

	// two
	lo = 1, hi = min(n, m);
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int K = mid;
		bool yes = false;

		FOR(i, 1, n) FOR(j, 1, m) if (i + K - 1 <= n && j + K - 1 <= m) {
			yes |= two.getSum(i, i + K - 1, j, j + K - 1) == K * K;
			if (yes)
				break;
		}
		if (yes)
			best2 = K, lo = mid + 1;
		else
			hi = mid - 1;
	}

	while (Q--) {
		int K;
		cin >> K;
		char ch;
		cin >> ch;
		if (ch == 'M')
			cout << (best1 >= K ? "yes\n" : "no\n");
		if (ch == 'F')
			cout << (best2 >= K ? "yes\n" : "no\n");
	}
}
