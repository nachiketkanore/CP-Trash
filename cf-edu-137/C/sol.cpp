/**
 *    Author: Nachiket Kanore
 *    Created: Monday 17 October 2022 08:20:50 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX = 2e5 + 5;
int N, A[MAX];
bool covered[MAX];
int dp[2][MAX];

int go(int id, bool have) {
	if (id == 0)
		return 0;
	int& ans = dp[have][id];
	if (~ans)
		return ans;
	ans = 0;

	if (have) {
		if (covered[id]) {
			int c1 = A[id] + go(id - 1, true);
			ans = max(ans, c1);
		} else {
			int c1 = A[id] + go(id - 1, false);
			int c2 = 0 + go(id - 1, false);
			ans = max({ ans, c1, c2 });
		}
	} else {
		if (covered[id]) {
			int c1 = A[id] + go(id - 1, false);
			int c2 = 0 + go(id - 1, true);
			ans = max({ ans, c1, c2 });
		} else {
			int c1 = 0 + go(id - 1, false);
			ans = max(ans, c1);
		}
	}
	return ans;
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		char ch;
		cin >> ch;
		covered[i] = ch == '1';
		dp[0][i] = dp[1][i] = -1;
	}
	FOR(i, 1, N) cin >> A[i];
	cout << go(N, false) << '\n';
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
