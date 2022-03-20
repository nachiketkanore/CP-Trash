/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 09:27:28 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
	string S;
	cin >> S;
	int sum = 0;
	for (char ch: S) {
		sum += ch-'0';
	}
	int req = (9 - sum % 9) % 9;
	if (req > 0) {
		char add = (char)('0' + req);
		const int N = S.size();
		if (S[0] > add) {
			cout << add << S << '\n';
			return;
		}
		int i = 0;
		while (i < N && S[i] <= add) {
			cout << S[i];
			i++;
		}
		cout << add;
		while (i < N) {
			cout << S[i];
			i++;
		}
		cout << '\n';
	} else {
		string T; T += S[0]; T += (char)(req + '0');
		S = T + S.substr(1);
		cout << S << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}
