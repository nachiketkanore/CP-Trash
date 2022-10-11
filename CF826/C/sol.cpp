/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 08:29:13 PM IST
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
	int N;
	cin >> N;
	vector<int> A(N + 1), pref(N + 1);
	FOR(i, 1, N) {
		cin >> A[i];
		pref[i] = pref[i - 1] + A[i];
	}
	int ans = N;
	FOR(i, 1, N) {
		int want = pref[i];
		int curr = 0, len = 0;
		vector<int> lens;
		for (int i = 1; i <= N; i++) {
			curr += A[i];
			len++;
			if (curr == want) {
				lens.push_back(len);
				len = 0;
				curr = 0;
			} else if (curr > want) {
				break;
			}
		}
		int tot = 0;
		for (int l : lens)
			tot += l;
		if (tot == N) {
			ans = min(ans, *max_element(ALL(lens)));
		}
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
