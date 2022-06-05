/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 05 June 2022 01:52:45 PM IST
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

	int N, Q;
	cin >> N >> Q;

	map<int, int> A;
	int sum = 0;
	int last = -1;

	FOR(i, 1, N) {
		int u;
		cin >> u;
		A[i] = u;
		sum += u;
	}

	while (Q--) {
		int type, id, x;
		cin >> type;

		if (type == 1) {
			cin >> id >> x;
			if (A.count(id)) {
				sum = sum - A[id] + x;
			} else {
				assert(~last);
				sum = sum - last + x;
			}
			A[id] = x;
		} else {
			cin >> x;
			A.clear();
			last = x;
			sum = x * N;
		}

		cout << sum << '\n';
	}

	return 0;
}
