#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int maximumSafenessFactor(vector<vector<int>>& mat) {
		const int dx[4] = { 0, 0, 1, -1 };
		const int dy[4] = { 1, -1, 0, 0 };
		const int N = mat.size();
		queue<pair<int, int>> thieves;
		vector<vector<int>> D(N, vector<int>(N, 1000000));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mat[i][j] == 1) {
					thieves.push(make_pair(i, j));
					D[i][j] = 0;
				}
			}
		}
		auto inside = [&](int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; };
		while (!thieves.empty()) {
			auto [i, j] = thieves.front();
			thieves.pop();

			for (int id = 0; id < 4; id++) {
				int ni = i + dx[id], nj = j + dy[id];
				if (!inside(ni, nj))
					continue;
				if (1 + D[i][j] < D[ni][nj]) {
					thieves.push(make_pair(ni, nj));
					D[ni][nj] = D[i][j] + 1;
				}
			}
		}

		auto reachable = [&](int keep) {
			vector<vector<bool>> vis(N, vector<bool>(N, false));
			function<void(int, int, int)> dfs = [&](int i, int j, int keep) {
				if (!inside(i, j) || D[i][j] < keep || vis[i][j])
					return;
				vis[i][j] = true;
				for (int id = 0; id < 4; id++) {
					dfs(i + dx[id], j + dy[id], keep);
				}
			};
			dfs(0, 0, keep);
			return vis[N - 1][N - 1] == true;
		};

		// binary search on the answer
		int lo = 0, hi = N * N;
		int ans = -1;

		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (reachable(mid)) {
				ans = max(ans, mid);
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return ans;
	}
};
