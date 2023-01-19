/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 17 March 2022 10:35:22 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _ = 2e5 + 5;
int N, x[_], y[_];
string S;
map<int, vector<int>> L, R;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	cin >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'L') {
			L[y[i]].push_back(x[i]);
		} else {
			R[y[i]].push_back(x[i]);
		}
	}
	bool found = false;
	for (auto [y, gleft] : L) {
		if (!R.count(y))
			continue;
		if (R[y].empty())
			continue;
		int sx = *min_element(R[y].begin(), R[y].end());
		for (int x : gleft) {
			if (sx < x) {
				found = true;
				break;
			}
		}
	}
	cout << (found ? "Yes\n" : "No\n");
	return 0;
}
