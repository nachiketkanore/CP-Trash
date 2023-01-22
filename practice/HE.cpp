#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

string s;
int n;
int dp[5][N];

int go(int id, char prev) {
	if (id == n)
		return 1;
	int& ans = dp[prev - 'a'][id];
	if (~ans)
		return ans;
	ans = 0;
	if (s[id] != '?') {
		ans |= go(id + 1, s[id]);
	} else {
		for (char ch = 'a'; ch <= 'b'; ch++) {
			if (prev == 'a' && ch == 'a')
				continue;
			ans |= go(id + 1, ch);
		}
	}
	return ans;
}

void trace(int id, char prev) {
	if (id == n)
		return;
	int ans = go(id, prev);
	if (s[id] != '?') {
		if (ans == go(id + 1, s[id])) {
			cout << s[id];
			return trace(id + 1, s[id]);
		} else
			assert(0);
	} else {
		for (char ch = 'a'; ch <= 'b'; ch++) {
			if (prev == 'a' && ch == 'a')
				continue;
			if (ans == go(id + 1, ch)) {
				cout << ch;
				return trace(id + 1, ch);
			}
		}
		assert(0);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	n = sz(s);
	memset(dp, -1, sizeof(dp));
	bool found = go(0, 'c');
	assert(found);
	trace(0, 'c');
}