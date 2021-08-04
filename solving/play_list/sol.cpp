#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, m, start[N], finish[N], curr = 1;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	FOR(i,1,n) {
		int c, t;	cin >> c >> t;
		int tot = c * t;
		start[i] = curr;
		finish[i] = curr + tot - 1;
		curr = finish[i] + 1;
	}

	FOR(i,1,m) {
		int tim;	cin >> tim;
		int lo = 1, hi = n;
		int ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (tim <= finish[mid]) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		assert(~ans);
		assert(start[ans] <= tim && tim <= finish[ans]);
		cout << ans << '\n';
	}
}