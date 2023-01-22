#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, h, a[N];

int get_time(int k) {
	int ret = 0;
	FOR(i, 1, n) {
		ret += (a[i] + k - 1) / k;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> h;
		FOR(i, 1, n) cin >> a[i];
		int lo = 1, hi = inf;
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int req = get_time(mid);
			if (req <= h) {
				ans = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		cout << ans << '\n';
	}
}