/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 11:50:48 AM IST
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

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> answer(K + 2);
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		int each = cnt / K;
		cnt %= K;
		answer[1] += each;
		if (cnt > 0) {
			answer[1] += 1;
			answer[cnt + 1] -= 1;
		}
	}
	FOR(i, 1, K) {
		answer[i] += answer[i - 1];
		cout << answer[i] << " \n"[i == K];
	}
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
