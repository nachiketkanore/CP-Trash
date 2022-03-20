/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 09:27:28 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

void solve() {
	string A, B;
	cin >> A >> B;
	const int N = A.size();
	const int M = B.size();
	if (N > M) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int i = 0, j = 0;
	while (i < N && j < M) {
		if (A[i] == B[j]) {
			i++;
			j++;
		} else {
			j++;
		}
	}
	if (i == N) cout << M - N << '\n';
	else cout << "IMPOSSIBLE\n";
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
