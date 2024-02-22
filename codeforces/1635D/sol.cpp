/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 06:59:50 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 3e5;
const int MOD = 1e9 + 7;
int N, P, cache[_];

int go(int rem) {
	if (rem <= 0)
		return 0;
	int& ans = cache[rem];
	if (~ans)
		return ans;

	ans = 1 + go(rem - 1);
	if (rem >= 2) {
		ans += 1 + go(rem - 2);
	}
	ans %= MOD;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));

	int ans = 0;
	cin >> N >> P;
	while (N--) {
		int x;
		cin >> x;
		int len = 0;
		while (x) {
			++len;
			x /= 2;
		}
		int rem = P - len;
		if (rem > 0) {
			ans += 1 + go(rem);
		} else if (rem == 0) {
			ans += 1;
		}
		ans %= MOD;
	}
	cout << ans;
	return 0;
}
