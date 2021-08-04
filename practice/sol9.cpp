#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, m, k;

int get_less(int val) {
	int ret = 0;
	FOR(i,1,n) {
		// i-th row : i 2i 3i 4i .... mi
		// get from this row = k * i, k * i < val
		int get = 0;
		int lo = 1, hi = m;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int val_at_pos = mid * i;
			if (val_at_pos < val) {
				get = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		ret += get;
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;

	int ans = -1;
	int lo = 1, hi = n * m;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		int less = get_less(mid);
		if (less < k) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	// assert(get_less(ans) == k - 1);
	cout << ans;

}