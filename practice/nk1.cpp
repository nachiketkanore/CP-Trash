#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> positions(n + 1);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			positions[a[i]].push_back(i);
		}

		vector<int> ans(n + 1, inf);

		for (int val = 1; val <= n; val++) if (!positions[val].empty()) {
			int min_len = 0;
			min_len = max(min_len, positions[val].front() + 1);
			min_len = max(min_len, n - positions[val].back());

			for (int id = 1; id < sz(positions[val]); id++) {
				min_len = max(min_len, positions[val][id] - positions[val][id - 1]);
			}
			ans[min_len] = min(ans[min_len], val);
		}

		for (int i = 1; i <= n; i++) {
			ans[i] = min(ans[i], ans[i - 1]);
			if (ans[i] >= inf) cout << -1 << ' ';
			else cout << ans[i] << ' ';
		}
		cout << '\n';
	} 	
}