/*
Author: Nachiket Kanore
Created: Monday 07 December 2020 07:31:02 PM IST
(ツ) Listen to what you know instead of what you fear.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, a[N];
map<int, int> last;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		last[a[i]] = i;
	}

	int groups = 0;

	for (int i = 1; i <= n;) {
		int j = i;
		++groups;
		int right = last[a[i]];
		while (j <= n && j < right) {
			j++;
			if (j <= n)
				right = max(right, last[a[j]]);
		}
		i = j + 1;
	}

	int ans = 1;
	const int mod = 998244353;
	FOR(i, 1, groups - 1) ans = (ans << 1) % mod;
	cout << ans << "\n";
}
