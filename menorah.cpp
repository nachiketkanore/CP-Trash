/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 16 March 2022 04:39:38 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int N;
string A, B;
const int inf = 1e9;

int go(int id) {
	if (id == N) return 0;
	int ans = inf;
	if (A[id] == '1') {
		// take
		if (B[id] == '1') {
			ans = min(ans, 1 + go(id + 1));
		}
		// dont take
		if (B[id] == '0') {
			ans = min(ans, 0 + go(id + 1));
		}
	} else {
		if (B[id] == '1') {
			ans = min(ans, 0 + go(id + 1));
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		int ans = go(0);
		if (ans >= inf) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}
