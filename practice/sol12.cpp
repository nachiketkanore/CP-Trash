#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e13;

int n, k, a[N];

int get(int median) {
	int want = (n + 1) / 2, have = 0;
	int ret = 0;
	for (int i = n; i >= 1; i--) {
		ret += max(0LL, median - a[i]);
		have++;
		if (have == want)
			break;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);

	int lo = 0, hi = inf;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int req = get(mid);
		if (req <= k) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans;
}
/*
1 2 3 4 5

make x as median
cnt = (n + 1) / 2
no of elements >= x should be >= cnt
*/