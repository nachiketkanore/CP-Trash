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
		int n, k;
		cin >> n >> k;
		std::vector<int> a(n);
		for (int &x : a) cin >> x;
		int ans = 0;
		while (*max_element(a.begin(), a.end()) <= k) {
			int id = min_element(a.begin(), a.end()) - a.begin();
			bool change = false;
			for (int i = 0; i < n; i++) if (i != id) {
				int add = abs(k - a[i]) / a[id];
				ans += add;
				a[i] += add * a[id];
				change = add * a[id] > 0;
			}
			if (!change) break;
		}
		cout << ans << '\n';
	}
}