/*
Author: Nachiket Kanore
Created: Thursday 03 December 2020 12:18:03 AM IST
(ツ) You can complain because roses have thorns, or you can rejoice because thorns have roses.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

int n, a[N];
int K;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> K;
	FOR(i, 1, n) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	int ans = 0;

	FOR(i, 1, n) {
		int R = -1;
		int lo = i, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int sum = a[mid] - a[i - 1];
			if (sum >= K) {
				R = mid;
				hi = mid - 1;
			} else
				lo = mid + 1;
		}
		if (~R)
			ans += n - R + 1;
	}
	cout << ans;
}
