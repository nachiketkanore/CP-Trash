#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

map<int, bool> dp;

int go(int n) {
	if (dp.count(n))
		return dp[n];
	int ans = 0;
	if (n == 1)
		return 0;
	if (__builtin_popcountll(n) == 1)
		ans |= go(n >> 1) == 0;
	else {
		for (int i = 64; i >= 0; i--) {
			if ((1LL << i) < n) {
				ans |= go(n - (1LL << i)) == 0;
				break;
			}
		}
	}
	dp[n] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << (go(n) ? "Louise" : "Richard") << '\n';
	}
}