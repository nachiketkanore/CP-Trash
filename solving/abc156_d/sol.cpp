/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 12:30:51 PM IST
(ツ) You will not be punished for your anger, you will be punished by your anger.
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

int power(int a, int b, int mod) {
	a %= mod;
	int ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int fact(int X, int mod) {
	if (X <= 1)
		return 1;
	int ret = 1;
	FOR(i, 2, X) ret = (ret * i) % mod;
	return ret;
}

int nCr(int n, int r, int mod) {
	// fact(n) / fact(n-r) * fact(r)
	// n * (n-1) * ... * (n-a+1) / a * (a-1) * (a-2) * ... 1
	int N = 1, D = 1;

	FOR(i, 0, r - 1) {
		N = N * (n - i) % mod;
		D = D * (i + 1) % mod;
	}

	int ret = N * power(D, mod - 2, mod) % mod;
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int mod = 1e9 + 7;
	int n, a, b;
	cin >> n >> a >> b;
	int ans = power(2, n, mod) - 1;
	ans = (ans - nCr(n, a, mod) + mod) % mod;
	ans = (ans - nCr(n, b, mod) + mod) % mod;
	cout << ans;
}
