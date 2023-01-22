/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 03:30:52 PM IST
(ツ) Imagination is the living power and prime agent of all human perception.
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("equal.in","r",stdin);

	int T;
	cin >> T;
	while (T--) {
		int a[3];
		FOR(i, 0, 2) cin >> a[i];
		sort(a, a + 3);
		cout << (a[0] == a[1] || a[1] == a[2] ? "YES\n" : "NO\n");
	}
}
