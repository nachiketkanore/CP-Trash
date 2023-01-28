#include "bits/stdc++.h"
using namespace std;

vector<int> g[200001];
int N, dp[2][200001];

int go(int X, int P, int F) {
	int& ans = dp[F][X];
	if (~ans)
		return ans;
	ans = 0;
	int block2 = 0;
	for (int Y : g[X])
		if (Y != P)
			block2 += go(Y, X, false);

	for (int Y : g[X]) {
		if (Y ^ P) {
			if (!F) {
				int c1 = 1 + go(Y, X, true);
				int add = block2 - go(Y, X, false);
				ans = max(ans, c1 + add);
			}
		}
	}
	ans = max(ans, block2);
	return ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1, u, v; i < N; i++)
		cin >> u >> v, g[u].push_back(v), g[v].push_back(u);

	cout << max(go(1, 1, true), go(1, 1, false));
}
