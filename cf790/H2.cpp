/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct BIT {
	int N;
	vector<int> bit;

	void init(int n) {
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) {
		while (idx <= N) {
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	int pref(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r) {
		if (l > r)
			return 0;
		return pref(r) - pref(l - 1);
	}
};

void solve() {
	int N, ans = 0;
	cin >> N;
	int A[N], cnt[N + 1];
	memset(cnt, 0, sizeof(cnt));
	BIT bit;
	bit.init(N + 1);

	F0R(i, N) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	F0R(j, N) {
		ans += bit.rsum(A[j] + 1, N);
		bit.update(A[j], 1);
		// F0R(i, j) {
		// 	if (A[i] > A[j])
		// 		++ans;
		// }
	}
	FOR(i, 1, N) {
		int tot = cnt[i];
		ans += tot * (tot - 1) / 2;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
