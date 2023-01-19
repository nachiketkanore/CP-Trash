/**
 *    Author: Nachiket Kanore
 *    Created: Monday 07 March 2022 08:12:00 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = 998244353;

int32_t main() {
	int N, ans = 0;
	cin >> N;
	vector<int> tens{ 1 };
	for (int i = 0; i < 18; i++) {
		tens.push_back(tens.back() * 10);
	}
	assert(tens.back() == 1e18);
	for (int i = 1; i < (int)tens.size(); i++) {
		int L = tens[i - 1];
		int R = tens[i] - 1;
		if (N >= R) {
			int tot = R - L + 1;
			tot %= MOD;
			tot = tot * (tot + 1) / 2;
			tot %= MOD;
			ans += tot;
			ans %= MOD;
		} else if (N >= L) {
			int tot = N - L + 1;
			tot %= MOD;
			tot = tot * (tot + 1) / 2;
			tot %= MOD;
			ans += tot;
			ans %= MOD;
		} else
			break;
	}
	cout << ans << '\n';
	return 0;
}
