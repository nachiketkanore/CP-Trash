/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 02:50:03 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		vector<int> a(n); F0R (i,n) cin >> a[i];
		sort(ALL(a)); reverse(ALL(a));
		int ans = 0;
		F0R (i,n) {
			// a[i] + a[j] > k
			// a[j] > k - a[i]
			// j is prefix of array
			int lo = 0, hi = n - 1, j = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (a[mid] > k - a[i] ) j = mid, lo = mid + 1;
				else hi = mid - 1;
			}
			ans += j + 1;
		}
		F0R (i,n) if (a[i] + a[i] > k) --ans;
		assert(ans % 2 == 0);
		ans >>= 1;
		cout << ans << '\n';
	}
}
