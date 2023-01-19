#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, m;
pair<int, int> a[N];

int get(int cmax) {
	// return min balloons required with c[i] <= cmax
	int ret = 0;
	for (int i = n; i; i--) {
		int ci = max(0LL, a[i].first - cmax / a[i].second);
		// if (ci > cmax) return inf;
		ci = min(ci, cmax);
		int xi = a[i].first - ci / a[i].second;
		xi = max(0LL, xi);
		ret += xi;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	FOR(i, 1, n) cin >> a[i].first;
	FOR(i, 1, n) cin >> a[i].second;
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);

	int ans = inf;
	int lo = 0, hi = inf;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int req = get(mid);
		cerr << mid << " " << req << '\n';
		if (req >= m) {
			ans = req;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	// assert(ans != inf);
	cout << ans;
}