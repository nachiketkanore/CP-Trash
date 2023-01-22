#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int power(int a, int b, int mod) {
	a %= mod;
	int ret = 1;
	while (b > 0) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return ret;
}

void solve() {
	int x, n;
	cin >> x >> n;
	int expo = 0;
	if (n < 5) {
		expo = 1;
		for (int i = 2; i <= n; i++) {
			expo = expo * i % 10;
		}
	}

	int ans = power(x, expo, 10);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T = 1;
	while (T--)
		solve();
}