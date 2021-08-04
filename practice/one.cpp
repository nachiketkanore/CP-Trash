#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<int> ans[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int x = 0; ; x++) {
		if (3 * x > 1000) break;
		for (int y = 0; ; y++) {
			if (3 * x + 5 * y > 1000) break;
			for (int z = 0; ; z++) {
				if (3 * x + 5 * y + 7 * z > 1000) break;
				int val = 3 * x + 5 * y + 7 * z;
				if (ans[val].empty()) {
					ans[val] = {x, y, z};
				}
			}
		}
	}
	
	int T;	cin >> T;
	while (T--) {
		int n;	cin >> n;
		if (ans[n].empty()) cout << -1 << '\n';
		else cout << ans[n][0] << ' ' << ans[n][1] << ' ' << ans[n][2] << '\n';
	}
}