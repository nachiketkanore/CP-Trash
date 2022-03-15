/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 10:59:38 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		sort(S.begin(), S.end());
		bool ok = true;
		for (int i = 1; i < (int)S.size(); i++) {
			ok &= (S[i] - S[i - 1]) <= 1;
		}
		cout << (ok ? "1D\n": "0D\n");
	}
	return 0;
}
