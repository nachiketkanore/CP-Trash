/**
 *    Author: Nachiket Kanore
 *    Created: Monday 12 February 2024 08:05:38 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N, ans = 0;
		string S;
		cin >> N >> S;
		for (int i = 0; i < N; i++) {
			int prev_counts = 0, sum = 0, curr_minuses = 0;
			for (int j = i; j < N; j++) {
				if (S[j] == '+') {
					prev_counts += curr_minuses / 2;
					curr_minuses = 0;
					sum++;
				} else {
					curr_minuses++;
					sum--;
				}
				if (sum == 0) {
					++ans;
				} else if (sum < 0 && sum % 3 == 0) {
					int req = -sum / 3;
					int ops = prev_counts + curr_minuses / 2;
					ans += req <= ops;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
