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

	int n;
	cin >> n;
	int f[10] = {};
	bool even = false;
	FOR(i, 1, n) {
		int d;
		cin >> d;
		f[d]++;
		even |= d % 2 == 0;
	}
	if (!even)
		cout << -1;
	else {
		int last = -1;
		FOR(i, 0, 9) if (i % 2 == 0 && f[i] > 0) {
			f[i]--;
			last = i;
			break;
		}
		assert(~last);
		for (int i = 9; i >= 0; i--) {
			while (f[i]-- > 0)
				cout << i;
		}
		cout << last;
	}
}