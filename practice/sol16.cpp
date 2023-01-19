#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

const int LOG = 30;
int n, cnt[LOG + 1][N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		int val;
		cin >> val;
		for (int bit = 0; bit <= LOG; bit++) {

			int next = val | (1 << bit);
			for (int j = LOG; j >= 0; j--)
				if (j != bit)
					if (next >> j & 1) {
						if ((next - (1 << j)) >= val) {
							next -= (1 << j);
						}
					}

			assert(next >= val && (next >> bit & 1));
			int add = next - val;
			cnt[bit][i] += add;
			cnt[bit][i] += cnt[bit][i - 1];
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int L, R;
		cin >> L >> R;
		int len = R - L + 1;
		int ans = inf;

		for (int bit = 0; bit <= LOG; bit++) {
			int have = cnt[bit][R] - cnt[bit][L - 1];
			ans = min(ans, have);
		}

		assert(ans != inf);
		cout << ans << '\n';
	}
}