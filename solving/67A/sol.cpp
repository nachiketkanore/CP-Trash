#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

const int K = 2002;
int n;
string s;
int dp[2][K + 5][K + 5];

int go(int id, int prev, int same) {
	if (prev < 1 || prev > K)
		return inf;
	if (id == sz(s))
		return 0;

	int& ans = dp[same][id][prev];
	if (~ans)
		return ans;
	ans = inf;

	if (s[id] == '=') {
		int get = prev + go(id + 1, prev, 0);
		ans = min(ans, get);
	}

	if (s[id] == 'L') {
		if (same) {
			int ch1 = prev + go(id + 1, prev, 0);
			int ch2 = go(id, prev - 1, 1);
			ans = min({ ans, ch1, ch2 });
		} else {
			int get = go(id, prev - 1, 1);
			ans = min(ans, get);
		}
	}

	if (s[id] == 'R') {
		if (same) {
			int ch1 = prev + go(id + 1, prev, 0);
			int ch2 = go(id, prev + 1, 1);
			ans = min({ ans, ch1, ch2 });
		} else {
			int get = go(id, prev + 1, 1);
			ans = min(ans, get);
		}
	}

	return ans;
}

void trace(int id, int prev, int same) {
	if (prev < 1 || prev > K) {
		assert(0);
		return;
	}
	if (id == sz(s))
		return;

	int ans = go(id, prev, same);

	if (s[id] == '=') {
		int get = prev + go(id + 1, prev, 0);
		if (get == ans) {
			cout << prev << ' ';
			return trace(id + 1, prev, 0);
		}
	}

	if (s[id] == 'L') {
		if (same) {
			int ch1 = prev + go(id + 1, prev, 0);
			int ch2 = go(id, prev - 1, 1);
			if (ch1 == ans) {
				cout << prev << ' ';
				return trace(id + 1, prev, 0);
			}
			if (ch2 == ans) {
				return trace(id, prev - 1, 1);
			}
		} else {
			int get = go(id, prev - 1, 1);
			if (get == ans) {
				return trace(id, prev - 1, 1);
			}
		}
	}

	if (s[id] == 'R') {
		if (same) {
			int ch1 = prev + go(id + 1, prev, 0);
			int ch2 = go(id, prev + 1, 1);
			if (ch1 == ans) {
				cout << prev << ' ';
				return trace(id + 1, prev, 0);
			}
			if (ch2 == ans) {
				return trace(id, prev + 1, 1);
			}
		} else {
			int get = go(id, prev + 1, 1);
			if (get == ans) {
				return trace(id, prev + 1, 1);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> s;
	int ans = inf;

	memset(dp, -1, sizeof(dp));
	FOR(give, 1, K) {
		int get = give + go(0, give, 0);
		ans = min(ans, get);
	}

	FOR(give, 1, K) {
		int get = give + go(0, give, 0);
		if (get == ans) {
			cout << give << ' ';
			trace(0, give, 0);
			break;
		}
	}
}