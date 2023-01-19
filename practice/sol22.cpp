#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int mod = 1e9 + 7;

vector<int> a(5), b(5);
int n = 5;

int go(int rem, int prev_id, int consec) {
	if (rem < 0)
		return 0;
	if (consec > b[prev_id])
		return 0;
	if (rem == 0) {
		int tot = accumulate(a.begin(), a.end(), 0LL);
		assert(tot == 0);
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int take = 1; take <= b[i]; take++) {
			a[i] -= take;
			ans = (ans + go(rem - take, i, prev_id == i ? consec + take : take));
			a[i] += take;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	FOR(i, 0, 4) cin >> a[i];
	FOR(i, 0, 4) cin >> b[i];
	int tot = accumulate(a.begin(), a.end(), 0LL);
	int ans = go(tot, 6, 0);
	cout << ans << '\n';
}