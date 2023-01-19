#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int LOG = 30;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	int ans = 0;

	for (int bit = LOG; ~bit; --bit) {
		int want = ans | (1LL << bit);
		int cnt = 0;
		for (int& x : a) {
			cnt += (x & want) == want;
		}
		if (cnt >= 2) {
			ans |= 1LL << bit;
		}
	}
	cout << ans;
}