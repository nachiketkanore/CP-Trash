/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 08:56:42 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = 1e9 + 7;
int M;
vector<int> fibs;

int go(int rem, int k, int id) {
	if (rem == 0 && k == 0)
		return 1;

	if (rem <= 0 || k <= 0 || id < 0)
		return 0;

	if (k * fibs[id] < rem)
		return 0;

	int ans = go(rem, k, id - 1);
	if (rem >= fibs[id]) {
		ans += go(rem - fibs[id], k - 1, id);
	}
	if (ans >= MOD)
		ans -= MOD;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fibs.push_back(1);
	fibs.push_back(2);
	while (fibs.back() < 5e9) {
		const int N = fibs.size();
		fibs.push_back(fibs[N - 1] + fibs[N - 2]);
	}
	M = fibs.size();
	int T;
	cin >> T;
	while (T--) {
		int X, K;
		cin >> X >> K;
		int id = M - 1;
		while (fibs[id] > X)
			id--;
		cout << go(X, K, id) << '\n';
	}
	return 0;
}
