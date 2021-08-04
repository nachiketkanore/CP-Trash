#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int ans;

int chk(int one, int two) {
	int mask1 = 0, mask2 = 0;
	while (one) mask1 |= (1 << (one % 10)), one /= 10;
	while (two) mask2 |= (1 << (two % 10)), two /= 10;
	return __builtin_popcountll(mask2 & mask1) > 0;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;	cin >> n;
	for (int d = 1; d * d <= n; d++) if (n % d == 0) {
		ans += chk(n, d);
		if (n / d != d)
			ans += chk(n, n / d);
	}
	cout << ans;
}