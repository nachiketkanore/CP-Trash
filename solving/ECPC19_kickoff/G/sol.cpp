/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 03:34:11 PM IST
(ツ) In three words I can sum up everything Ive learned about life: it goes on.
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

	// freopen("gcd.in","r",stdin);
	int T;
	cin >> T;
	int ans = 0;
	while (T--) {
		int L, R;
		cin >> L >> R;
		ans = __gcd(ans, L);
		FOR(i, L, min(L + 5, R)) ans = __gcd(ans, i);
		cout << ans << "\n";
	}
}
