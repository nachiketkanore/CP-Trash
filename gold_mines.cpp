/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 01:04:43 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1002;
int N, M, mat[_][_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> mat[i][j];
			mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << mat[r2][c2] - mat[r2][c1 - 1] - mat[r1 - 1][c2] + mat[r1 - 1][c1 - 1] << '\n';
	}
	return 0;
}
