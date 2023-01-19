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

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		bool good = false;
		FOR(i, 1, n) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			good |= b == c;
		}
		good &= m % 2 == 0;
		cout << (good ? "YES" : "NO") << '\n';
	}
}