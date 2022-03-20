/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 05:29:56 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int N; cin >> N;
	int tot = 2 * N + 1;
	set<int> f;
	for (int i = 1; i <= tot; i++) {
		f.insert(i);
	}
	while (tot--) {
		int me = *f.begin();
		f.erase(me);
		cout << me << endl;
		int he; cin >> he;
		assert(f.count(he));
		f.erase(he);
	}
	return 0;
}
