#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

void test() {
	#define endl '\n'
	int T; cin >> T;
	while (T--) {
		int n, sum = 0;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a.begin(), a.end());
		int high = a.back() - a.front();
		cout << high << ' ' << sum << endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;	cin >> T;
	while (T--) {
		int cnt = 2;
		int n, x;
		cin >> n >> x;
		if (n == 1 || n == 2) {
			cout << 1 << '\n';
			continue;
		}

		int ans = -1;
		int lo = 1, hi = 1e9;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int cnt = 0;
			if (mid == 1) cnt = 2;
			else {
				cnt = 2 + (mid - 1) * x;
			}
			if (cnt <= n) {
				ans = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		assert(~ans);
		int get = (ans - 1) * x + 2;
		if (get < n) ++ans;
		cout << ans << '\n';
	}
}
