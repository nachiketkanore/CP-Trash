#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e6 + 1, M = 1e5 + 5, inf = 1e18, mod = 1e9 + 7;

bool prime[N + 5];
set<int> pc;

void pre() {
	fill(prime + 2, prime + N, true);
	for (int i = 2; i < N; i++)
		if (prime[i]) {
			int cube = i * i * i;
			pc.insert(cube);
			for (int j = 2 * i; j < N; j += i)
				prime[j] = false;
		}
}

int32_t main() {
	ios::sync_with_stdio(false);

	pre();

	int n, q;
	cin >> n >> q;
	int cnt[n + 2] = { 0 };
	for (int i = 1, u; i <= n; i++) {
		cin >> u;
		if (pc.count(u))
			cnt[i] = 1;
	}

	for (int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (cnt[r] - cnt[l - 1]) << endl;
	}
}