/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 09:27:28 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _ = 5e4 + 2;
int N;
string S;
bool vis[2][2][2][2][2][_];
bool dp[2][2][2][2][2][_];

vector<int> get(int id) {
	if (S[id] == '?') return {0, 1};
	return {S[id]-'0'};
}

bool pal(int a, int b, int c, int d, int e) {
	if (a == e && b == d) return true;
	return false;
}

bool pal(int a, int b, int c, int d, int e, int f) {
	if (a == f && b == e && c == d) return true;
	return false;
}

bool go(int id, int a, int b, int c, int d, int e) {
	if (pal(a, b, c, d, e)) return false;
	if (id == N) return true;
	if (vis[a][b][c][d][e][id])
		return dp[a][b][c][d][e][id];
	vis[a][b][c][d][e][id] = true;
	bool ans = false;
	if (S[id] == '?') {
		for (int put: get(id)) {
			if (!pal(a, b, c, d, e, put)) {
				ans |= go(id + 1, b, c, d, e, put);
			}
		}
	} else {
		int curr = S[id]-'0';
		if (!pal(a, b, c, d, e, curr)) {
			ans |= go(id + 1, b, c, d, e, curr);
		}
	}
	dp[a][b][c][d][e][id] = ans;
	return ans;
}

void solve() {
	cin >> N >> S;
	if (N < 5) {
		cout << "POSSIBLE\n";
		return;
	}
	memset(vis, false, sizeof(vis));
	memset(dp, false, sizeof(dp));
	bool ans = false;
	for (int a: get(0)) {
		for (int b: get(1)) {
			for (int c: get(2)) {
				for (int d: get(3)) {
					for (int e: get(4)) {
						if (!pal(a, b, c, d, e)) {
							ans |= go(5, a, b, c, d, e);
						}
						if (ans) {
							cout << "POSSIBLE\n";
							return;
						}
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
