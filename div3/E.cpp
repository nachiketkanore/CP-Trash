/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 12:14:38 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

string S;
int N;

int go(int id, int c0, int c1, int c2) {
	if (id == -1) {
		return !c0 && !c1 && !c2;
	}
	int ans = 0;
	for (int d1 = 0; d1 < 10; d1++) {
		for (int d2 = 0; d2 < 10; d2++) {
			int curr = (c0 + d1 + d2) % 10;
			int nc0 = curr / 10;
			if (curr != S[id]-'0') continue;
			ans += go(id - 1, c1, c2 + nc0, 0);
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int u; cin >> u;
		S = to_string(u);
		N = S.size();
		int ans = go(N - 1, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}
