/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 18 January 2022 03:29:16 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	vector<int> vals;
	for (int i = 1;; i++) {
		int sod = 0;
		int val = i;
		while (val) {
			sod += val % 10;
			val /= 10;
		}
		if (sod % 4 == 0) {
			vals.push_back(i);
			if (i > 1000)
				break;
		}
	}
	int tests;
	for (cin >> tests; tests > 0; tests--) {
		int N;
		cin >> N;
		int id = lower_bound(vals.begin(), vals.end(), N) - vals.begin();
		assert(id < (int)vals.size());
		cout << vals[id] << '\n';
	}
	return 0;
}
