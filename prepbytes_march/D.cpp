/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 11:15:52 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> blues, reds, A(N);
		string colors;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			if (colors[i] == 'B') {
				blues.push_back(A[i]);
			} else {
				reds.push_back(A[i]);
			}
		}
		sort(blues.begin(), blues.end()); // minus
		sort(reds.begin(), reds.end());	  // plus
		if (!reds.empty() && reds.back() > N) {
			cout << "NO\n";
			continue;
		} else if (!blues.empty() && blues[0] < 1) {
			cout << "NO\n";
			continue;
		}
	}
	return 0;
}
