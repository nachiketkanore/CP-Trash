/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 25 May 2022 11:56:08 AM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int INF = 1e9;
int N, X;
map<int, int> dp;

int go(int curr) {
	string number = to_string(curr);
	if (sz(number) == N)
		return 0;
	if (sz(number) > N)
		return INF;

	if (dp.count(curr))
		return dp[curr];
	int ans = INF;

	for (char ch : number) {
		if ((ch - '0') >= 2) {
			ans = min(ans, 1 + go(curr * (ch - '0')));
		}
	}

	dp[curr] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> X;

	int answer = go(X);
	if (answer == INF)
		answer = -1;

	cout << answer << '\n';

	return 0;
}
