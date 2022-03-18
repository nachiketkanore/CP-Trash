/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 17 March 2022 10:27:31 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int V, A, B, C;
	cin >> V >> A >> B >> C;
	int tot = (A + B + C);
	V %= tot;
	if (V < A) {
		cout << "F\n";
		return 0;
	} else {
		V -= A;
	}
	if (V < B) {
		cout << "M\n";
		return 0;
	} else {
		V -= B;
	}
	if (V < C) {
		cout << "T\n";
		return 0;
	} else {
		V -= C;
	}
	assert(false);
	return 0;
}
