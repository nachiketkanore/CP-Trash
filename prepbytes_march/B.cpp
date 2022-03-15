/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 11:03:04 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, C;
		cin >> N >> C;
		if (N == 0) cout << "0\n";
		else {
			cout << (N + C - 1) / C << '\n';
		}
	}
	return 0;
}
