#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e12;

int n, tot, x[N];

bool canPlace(int dist) {
	int placed = 0;
	int curr = 1;

	while (1) {
		++placed;

		int lo = curr + 1, hi = n;
		int next = curr;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (x[mid] - x[curr] >= dist) {
				next = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if (next == curr) break;
		curr = next;

	}

	return placed >= tot;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> tot;
		FOR(i,1,n) cin >> x[i];
		sort (x + 1, x + n + 1);

		int ans = 0;
		int lo = 1, hi = inf;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (canPlace(mid)) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		assert(ans > 0);
		cout << ans << '\n';
	}	
}