/*
Author: Nachiket Kanore
Created: Saturday 28 November 2020 06:44:15 PM IST
(ツ) A day of worry is more exhausting than a day of work.
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

const int N = 2e5 + 5, inf = 1e18;

int n, m, a[N], pref[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	FOR(i, 1, n) {
		pref[i] = a[i] + pref[i - 1];
	}
	int curr_ans = 0;
	FOR(i, 1, n) {
		if (i % m == 1) {
			curr_ans += pref[i - 1];
		}
		curr_ans += a[i];
		cout << curr_ans << " \n"[i == n];
	}
}
