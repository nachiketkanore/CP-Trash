#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		const int LOG = 30;
		vector<int> cnt(LOG + 1, 0);
		int ans = 0;

		FOR(i, 1, n) {
			int val;
			cin >> val;
			int last = -1;
			for (int bit = LOG; ~bit; --bit)
				if (val >> bit & 1) {
					last = bit;
					break;
				}
			assert(~last);
			ans += cnt[last];
			cnt[last]++;
		}

		cout << ans << '\n';
	}
}
/*
a xor b = (a & b`) or (a` & b)
(a & b) - (a xor b) >= 0
(a & b) - (a + b - 2 * (a & b)) >= 0
3 * (a & b) - (a + b) >= 0
a + b = (a xor b) + 2 * (a & b)

*/