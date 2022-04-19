/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 April 2022 04:24:25 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int N, M;
string S, T;
bool ban[1000];
int dp[5000][5000];

int go(int i, int j) {
	if (i == N || j == M)
		return 0;
	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = 0;
	if (S[i] == T[j] && !ban[S[i]]) {
		ans = max(ans, 1 + go(i + 1, j + 1));
		ans = max(ans, 0 + go(i + 1, j + 1));
	}
	ans = max(ans, 0 + go(i + 1, j));
	ans = max(ans, 0 + go(i, j + 1));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> T;
	N = S.size(), M = T.size();
	for (char ch : "aeiou")
		ban[ch] = true;
	F0R(i, N) F0R(j, M) dp[i][j] = -1;
	cout << go(0, 0);
	return 0;
}
