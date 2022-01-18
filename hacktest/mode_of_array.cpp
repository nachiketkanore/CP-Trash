/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 18 January 2022 03:37:25 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int tests;
	for (cin >> tests; tests > 0; tests--) {
		int N, K; cin >> N >> K;
		map<int,int> freq;
		for (int i = 0, u; i < N; i++) {
			cin >> u;
			freq[u]++;
		}
		int k_freq = freq[K];
		int ans = 0;
		int most_freq = 0;
		for (auto [val, cnt]: freq) {
			most_freq = max(most_freq, cnt);
			if (cnt > k_freq) {
				ans += k_freq - cnt;
			} else if (cnt == k_freq && K != val) {
				ans += 1;
			}
		}
		if (k_freq == 0) {
			ans = most_freq;
		}
		cout << ans << '\n';
	}
	return 0;
}
