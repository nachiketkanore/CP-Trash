/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 11:06:29 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		const string T = "APRIL";
		int cnt[26] = {};
		for (int i = 0; i < N; i++) {
			string S;
			cin >> S;
			cnt[S[0] - 'A']++;
		}
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = i + 1; j < 5; j++) {
				for (int k = j + 1; k < 5; k++) {
					ans += cnt[T[i] - 'A'] * cnt[T[j] - 'A'] * cnt[T[k] - 'A'];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
