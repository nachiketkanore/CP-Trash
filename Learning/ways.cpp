#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dp[105][105];

int countWays(int index, int cnt) {
	if (index == n)
		return cnt == k;

	int& ans = dp[index][cnt];
	if (~ans)
		return ans;
	ans = 0;

	ans += countWays(index + 1, cnt);
	ans += (m - 1) * countWays(index + 1, cnt + 1);

	return ans;
}

int main() {
	while (cin >> n >> m >> k) {
		memset(dp, -1, sizeof(dp));
		cout << m * countWays(1, 0) << '\n';
	}
}
