/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 02:05:22 PM IST
(ツ) If you're not prepared to be wrong, you'll never come up with anything original.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;

bool prime[N + 1];
int cnt[N + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(prime + 2, prime + N + 1, true);
	FOR(i, 2, N) if (prime[i]) {
		cnt[i] = 1;
		for (int j = 2 * i; j <= N; j += i)
			prime[j] = false;
	}
	FOR(i, 1, N) cnt[i] += cnt[i - 1];

	int a, b, k;
	cin >> a >> b >> k;

	auto ok = [&](int l) {
		bool poss = true;
		FOR(x, a, b - l + 1)
		poss &= (cnt[x + l - 1] - cnt[x - 1]) >= k;
		return poss;
	};

	int lo = 1, hi = b - a + 1;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid))
			ans = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << ans << "\n";
}
