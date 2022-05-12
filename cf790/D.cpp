/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, M;
	cin >> N >> M;
	int mat[N][M];
	F0R(i, N) F0R(j, M) cin >> mat[i][j];
	int ans = 0;
	auto inside = [&](
				  int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; };
	F0R(i, N) {
		F0R(j, M) {
			int get = mat[i][j];
			{
				int ni = i - 1, nj = j - 1;
				while (inside(ni, nj)) {
					get += mat[ni][nj];
					ni--, nj--;
				}
			}
			{
				int ni = i + 1, nj = j + 1;
				while (inside(ni, nj)) {
					get += mat[ni][nj];
					ni++, nj++;
				}
			}
			{
				int ni = i - 1, nj = j + 1;
				while (inside(ni, nj)) {
					get += mat[ni][nj];
					ni--, nj++;
				}
			}
			{
				int ni = i + 1, nj = j - 1;
				while (inside(ni, nj)) {
					get += mat[ni][nj];
					ni++, nj--;
				}
			}

			ans = max(ans, get);
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
