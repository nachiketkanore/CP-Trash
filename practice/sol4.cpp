#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int cost[N], weight[N];
int n, total_weight, total_items;
int info[1 << 18];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> cost[i] >> weight[i];
		}
		cin >> total_weight >> total_items;
		int ans = 0;
		memset(info, 0, sizeof(info));
		for (int mask = 0; mask < (1 << n); mask++)
			if (__builtin_popcountll(mask) <= total_items) {
				int w = 0, sale = 0;
				for (int i = 0; i < n; i++)
					if ((mask >> i & 1)) {
						w += weight[i];
						sale += cost[i];
					}
				if (w <= total_weight) {
					ans = max(ans, sale);
				}
			}
		cout << "For Day #" << tt << ":\n";
		cout << (~ans ? ans : -1) << '\n';
	}
}