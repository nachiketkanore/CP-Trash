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

	// https://oeis.org/search?q=0+1+2+2+3+3+4+4+4+5&language=english&go=Search
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = (int)sqrt(4 * n - 1) - 1;
		cout << ans << '\n';
	}
}