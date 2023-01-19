/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 09:27:28 AM IST
 **/
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int INF = 1e15;
int sz = 0, tc;
int num[20];
int cnt[10][10];
int prod_dp[40][27][20][15];

int check(int x, int y, int z, int k, int sod) {
	if (sod == 0)
		return 0;
	int& prod = prod_dp[x][y][z][k];
	if (~prod)
		return prod % sod == 0;
	prod = 1;
	while (x--)
		prod *= 2;
	while (y--)
		prod *= 3;
	while (z--)
		prod *= 5;
	while (k--)
		prod *= 7;
	return prod % sod == 0;
}

// map<array<int,4>, int> cache[13][2][120][2][2];
int cache[13][2][8][6][6][6][120][2][2];

int dp(int idx, bool less, int x, int y, int z, int k, int sod, bool st, bool zero) {
	if (idx == sz) {
		if (zero && sod > 0)
			return 1;
		return check(x, y, z, k, sod);
	}
	if (x >= 7)
		x = 7;
	if (y >= 5)
		y = 5;
	if (z >= 4)
		z = 4;
	if (k >= 2)
		k = 2;
	int& ans = cache[idx][less][x][y][z][k][sod][st][zero];
	if (~ans)
		return ans;
	ans = 0;
	int lo = 0, hi = 9;
	if (!less)
		hi = num[idx];
	for (int i = lo; i <= hi; i++) {
		bool nzero = zero;
		nzero |= (st || i > 0) && i == 0;
		ans += dp(idx + 1, less | (i < num[idx]), x + cnt[i][2], y + cnt[i][3], z + cnt[i][5], k + cnt[i][7], sod + i, st || i > 0, nzero);
	}
	// cache[idx][less][sod][st][zero][{x, y, z, k}] = ans;
	return ans;
}

map<int, int> already;

int solve(int k) {
	if (already.count(k))
		return already[k];
	int K = k;
	if (k <= 10)
		return k;
	sz = 0;
	memset(cache, -1, sizeof(cache));
	// for (int i = 0; i < 13; i++) {
	// 	for (int j = 0; j < 2; j++) {
	// 		for (int k = 0; k < 2; k++) {
	// 			for (int l = 0; l < 2; l++) {
	// 				for (int s = 0; s < 120; s++) {
	// 					cache[i][j][s][k][l].clear();
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	while (k > 0) {
		num[sz++] = k % 10;
		k /= 10;
	}
	reverse(num, num + sz);
	int ans = dp(0, 0, 0, 0, 0, 0, 0, 0, 0);
	already[K] = ans;
	return ans;
}

int32_t main() {
	memset(prod_dp, -1, sizeof(prod_dp));
	for (int i = 1; i < 10; i++) {
		int val = i;
		while (val % 2 == 0)
			cnt[i][2]++, val /= 2;
		while (val % 3 == 0)
			cnt[i][3]++, val /= 3;
		while (val % 5 == 0)
			cnt[i][5]++, val /= 5;
		while (val % 7 == 0)
			cnt[i][7]++, val /= 7;
	}

	int t;
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		int A, B;
		cin >> A >> B;
		int ans = solve(B) - solve(A - 1);
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}
