#include "bits/stdc++.h"
typedef long long int ll;
using namespace std;
template <class T> bool ckmin(T& a, const T b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool ckmax(T& a, const T b) {
	return a < b ? a = b, 1 : 0;
}
string a, b, c;
int N, M, K, dp[22][22][22];

int rec(int i, int j, int k) {
	if (i == N || j == M || k == K) {
		return 0;
	}

	int& cur = dp[i][j][k];
	if (cur != -1)
		return cur;

	if (a[i] == b[j] && b[j] == c[k]) {
		return 1 + rec(i + 1, j + 1, k + 1);
	}

	int ans = 0;
	ckmax(ans, rec(i + 1, j, k));
	ckmax(ans, rec(i, j + 1, k));
	ckmax(ans, rec(i, j, k + 1));
	return cur = ans;
}

void solve() {
	cin >> a >> b >> c;
	N = a.size(), M = b.size(), K = c.size();
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0, 0) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	while (T--)
		solve();
	return 0;
}
