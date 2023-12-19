#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool dp[100][100][202];
bool vis[100][100][202];
class Solution {
	int N, M;

	bool go(int i, int j, int bal, vector<vector<char>>& mat) {
		if (bal < 0)
			return false;
		if (i == N - 1 && j == M - 1)
			return bal == 0;

		bool& ans = dp[i][j][bal];
		ans = 0;

		if (vis[i][j][bal])
			return ans;

		vis[i][j][bal] = true;

		if (i + 1 < N) {
			ans |= go(i + 1, j, bal + (mat[i + 1][j] == '(' ? 1 : -1), mat);
		}
		if (ans)
			return ans;
		if (j + 1 < M) {
			ans |= go(i, j + 1, bal + (mat[i][j + 1] == '(' ? 1 : -1), mat);
		}
		return ans;
	}

	public:
	bool hasValidPath(vector<vector<char>>& mat) {
		if (mat[0][0] == ')')
			return false;
		this->N = mat.size();
		this->M = mat[0].size();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				for (int b = 0; b <= N + M; b++)
					vis[i][j][b] = false;

		return go(0, 0, mat[0][0] == '(' ? +1 : -1, mat);
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<char>> mat = { { '(', '(' }, { '(', ')' }, { '(', ')' } };
	Solution solution;

	cout << solution.hasValidPath(mat) << endl;
	return 0;
}

