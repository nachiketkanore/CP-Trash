/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 13 February 2024 12:09:27 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q, k, x;
	cin >> Q;
	set<int> have = { 0 };
	map<int, int> kmex;
	while (Q--) {
		char op;
		cin >> op;
		if (op == '+') {
			cin >> x;
			have.insert(x);
		} else if (op == '?') {
			cin >> k;
			int m = kmex.count(k) ? kmex[k] : k;
			while (have.count(m)) {
				m += k;
			}
			kmex[k] = m;
			cout << m << '\n';
		}
	}

	return 0;
}
