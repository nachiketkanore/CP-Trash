/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 12:29:05 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		if (u & 1) cout << u << ' ';
		else cout << u - 1 << ' ';
	}
	return 0;
}
