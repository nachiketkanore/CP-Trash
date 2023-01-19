#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e3 + 5, mod = 1e9 + 7;

int n, m, ret;
char mat[2005][2005];
int dpl[N][N], dpu[N][N], dpr[N][N], dpd[N][N], p2[N * N];

bool inside(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int gor(int row, int col) {
	if (!inside(row, col))
		return 0;
	if (mat[row][col] == '#')
		return 0;
	int& ans = dpr[row][col];
	if (~ans)
		return ans;
	ans = 1 + gor(row, col + 1);
	return ans;
}

int god(int row, int col) {

	if (!inside(row, col))
		return 0;
	if (mat[row][col] == '#')
		return 0;
	int& ans = dpd[row][col];
	if (~ans)
		return ans;
	ans = 1 + god(row + 1, col);
	return ans;
}

int gou(int row, int col) {

	if (!inside(row, col))
		return 0;
	if (mat[row][col] == '#')
		return 0;
	int& ans = dpu[row][col];
	if (~ans)
		return ans;
	ans = 1 + gou(row - 1, col);
	return ans;
}

int gol(int row, int col) {

	if (!inside(row, col))
		return 0;
	if (mat[row][col] == '#')
		return 0;
	int& ans = dpl[row][col];
	if (~ans)
		return ans;
	ans = 1 + gol(row, col - 1);
	return ans;
}

int power(int x) {
	if (x == 0)
		return 1;
	assert(x >= 0);
	return p2[x];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	p2[0] = 1;
	for (int i = 1; i < N * N; i++)
		p2[i] = 2 * p2[i - 1] % mod;

	memset(dpl, -1, sizeof(dpl));
	memset(dpr, -1, sizeof(dpr));
	memset(dpd, -1, sizeof(dpd));
	memset(dpu, -1, sizeof(dpu));

	cin >> n >> m;
	int tot = 0;
	FOR(i, 1, n) FOR(j, 1, m) cin >> mat[i][j], tot += mat[i][j] == '.';

	FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] == '.') {
		int cnt = 1 + gol(i, j - 1) + gor(i, j + 1) + gou(i - 1, j) + god(i + 1, j);
		int other = tot - cnt;
		// cerr << i << ' ' <<  j << " : cnt = " << cnt << '\n';
		int add = (power(cnt) - 1) * power(other) % mod;
		ret = (ret + add) % mod;
	}
	cout << ret;
}