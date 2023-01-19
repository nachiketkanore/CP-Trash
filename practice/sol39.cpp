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
		std::vector<int> ans(n, -1);
		int k;
		cin >> k;
		int cless = 0, cequal = 0, cmore = 0;
		FOR(i, 1, n) {
			int u;
			cin >> u;
			if (k % 2 == 0 && u == k / 2) {
				cequal++;
			} else if (2 * u < k) {
				cless++;
				ans[i - 1] = 0;
			} else if (2 * u > k) {
				cmore++;
				ans[i - 1] = 1;
			} else
				assert(0);
		}
		assert(cequal + cless + cmore == n);
		bool give = 0;

		FOR(i, 1, n) if (ans[i - 1] == -1) {
			assert(cequal > 0);
			cequal--;
			ans[i - 1] = give;
			give ^= 1;
		}

		assert(!cequal);
		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}