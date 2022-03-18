/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 March 2022 11:52:22 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, X;
	string S;
	cin >> N >> X >> S;
	string pos;
	while (X > 0) {
		pos.push_back(char('0' + X%2));
		X >>= 1;
	}
	reverse(pos.begin(), pos.end());
	for (char ch: S) {
		if (ch == 'L') {
			pos.push_back('0');
		}
		else if (ch == 'R') {
			pos.push_back('1');
		}
		else {
			pos.pop_back();
		}
	}
	int ans = 0;
	for (char ch: pos) {
		ans = ans * 2 + (ch-'0');
	}
	cout << ans << '\n';
	return 0;
}
