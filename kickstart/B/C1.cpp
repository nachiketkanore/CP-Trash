/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 24 April 2022 04:49:28 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int INF = 1e18;
const int _ = 500;
int N, D, A[_];

void solve() {
	cin >> N >> D;
	bool ok = true;
	FOR(i, 1, N) {
		cin >> A[i];
		ok &= A[i] == 0;
	}
	int ans = 0;
	while (!ok) {
		vector<int> ind;
		FOR(i, 1, N) {
			if (A[i] == 1) {
				ind.push_back(i);
			}
		}
		int L = ind[0], R = ind.back();
		FOR(i, L, R) {
			A[i] ^= 1;
		}
		bool chk = true;
		FOR(i, 1, N) chk &= A[i] == 0;
		ok = chk;
		ans++;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
