/*
Author: Nachiket Kanore
Created: Saturday 07 November 2020 05:44:46 PM IST
Do not follow where the path may lead. Go, instead, where there is no path and leave a trail.
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

const int SZ = 1000 + 5, inf = 1e18;

int mat[SZ][SZ];

struct BIT2D {
	int bit[SZ + 1][SZ + 1];
	void upd(int X, int Y, int val) {
		for (; X <= SZ; X += (X & -X))
			for (int Y1 = Y; Y1 <= SZ; Y1 += (Y1 & -Y1))
				bit[X][Y1] += val;
	}
	int query(int X, int Y) {
		int ans = 0;
		for (; X > 0; X -= (X & -X))
			for (int Y1 = Y; Y1 > 0; Y1 -= (Y1 & -Y1))
				ans += bit[X][Y1];
		return ans;
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
} bit[10];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, Q;
	cin >> n >> Q;

	FOR(i, 1, n) FOR(j, 1, n) {
		int val;
		cin >> val;
		mat[i][j] = val;
		bit[val].upd(i, j, 1);
	}

	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int r1, r2, c1, c2, k;
			cin >> r1 >> r2 >> c1 >> c2 >> k;
			cout << bit[k].getSum(r1, r2, c1, c2) << "\n";
		} else if (type == 2) {
			int r1, r2, c1, c2, k;
			cin >> r1 >> r2 >> c1 >> c2 >> k;
			int ans = 0;
			FOR(val1, 1, 9) FOR(val2, val1, 9) {
				if (val1 + val2 != k)
					continue;
				if (val1 == val2) {
					int cnt = bit[val1].getSum(r1, r2, c1, c2);
					ans += cnt * (cnt - 1) / 2;
				} else {
					ans += bit[val1].getSum(r1, r2, c1, c2) * bit[val2].getSum(r1, r2, c1, c2);
				}
			}
			cout << ans << "\n";
		} else {
			int r, c, k;
			cin >> r >> c >> k;
			int old = mat[r][c];
			mat[r][c] = k;
			bit[old].upd(r, c, -1);
			bit[k].upd(r, c, 1);
		}
	}
}
