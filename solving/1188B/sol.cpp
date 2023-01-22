/*
Author: Nachiket Kanore
Created: Saturday 12 December 2020 11:57:44 PM IST
(ツ) Write your plans in pencil and give God the eraser.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	FOR(i, 1, b) ret = (ret * a) % mod;
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p, k;
	cin >> n >> p >> k;

	map<int, int> cnt;
	int ans = 0;

	FOR(i, 1, n) {
		int u;
		cin >> u;
		// same = u^4 - ku
		int same = (power(u, 4, p) - (k * u % p) + p) % p;
		ans += cnt[same];
		cnt[same]++;
	}

	cout << ans;
}
