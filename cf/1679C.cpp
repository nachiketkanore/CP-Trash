/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 May 2022 10:45:07 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) {
		while (idx <= N) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r) {
		return pref(r) - pref(l - 1);
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;
	BIT row_cnt, col_cnt;
	row_cnt.init(N);
	col_cnt.init(N);
	vector<int> row(N + 1), col(N + 1);
	while (Q--) {
		int type, x1, y1;
		cin >> type >> x1 >> y1;
		if (type == 1) {
			row[x1]++;
			col[y1]++;
			if (row[x1] == 1) {
				row_cnt.update(x1, 1);
			}
			if (col[y1] == 1) {
				col_cnt.update(y1, 1);
			}
		} else if (type == 2) {
			row[x1]--;
			col[y1]--;
			if (row[x1] == 0) {
				row_cnt.update(x1, -1);
			}
			if (col[y1] == 0) {
				col_cnt.update(y1, -1);
			}
		} else if (type == 3) {
			int x2, y2;
			cin >> x2 >> y2;
			bool okay = row_cnt.rsum(x1, x2) == x2 - x1 + 1 || col_cnt.rsum(y1, y2) == y2 - y1 + 1;
			cout << (okay ? "Yes\n" : "No\n");
		}
	}

	return 0;
}
