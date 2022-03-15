/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 11:45:41 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _ = 3005;
int N, X, dp[_][_];
vector<pair<int,int>> A;

int go(int id, int curr_day) {
	if (curr_day > X || id == N) return 0;
	int &ans = dp[id][curr_day];
	if (~ans) return ans;
	ans = go(id + 1, curr_day);
	ans = max(ans, A[id].second + go(id + 1, curr_day + A[id].first));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N >> X;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	cout << go(0, 1) << '\n';
	return 0;
}
