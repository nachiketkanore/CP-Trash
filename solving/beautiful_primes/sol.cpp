/*
Author: Nachiket Kanore
Created: Friday 11 December 2020 07:03:56 PM IST
(ツ) The secret to a rich life is to have more beginnings than endings.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int n, p[N], a[N];

void solve() {
	cin >> n;
	FOR(i, 1, n) cin >> p[i];
	FOR(i, 1, n) cin >> a[i];

	int ans = 1;
	const int mod = 1e9 + 7;

	FOR(i, 1, n) {
		int num = p[i] * (power(p[i], a[i], mod) - 1) % mod;
		int den = power(p[i] - 1, mod - 2, mod);
		int mul = num * den % mod;
		ans = (ans * mul) % mod;
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
