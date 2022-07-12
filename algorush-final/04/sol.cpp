/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 01:10:10 PM IST
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

void solve() {
	int N;
	cin >> N;
	vector<int> rowlen(N);
	F0R(i, N) {
		cin >> rowlen[i];
	}

	vector<vector<int>> one, two;

	F0R(i, N) {
		vector<int> row(rowlen[i]);
		for (int& x : row)
			cin >> x;
		sort(ALL(row));
		one.push_back(row);
	}

	int M;
	cin >> M;
	vector<int> rowlen2(M);
	F0R(i, M) {
		cin >> rowlen2[i];
	}

	F0R(i, M) {
		vector<int> row(rowlen2[i]);
		for (int& x : row)
			cin >> x;
		sort(ALL(row));
		two.push_back(row);
	}

	sort(ALL(one));
	sort(ALL(two));

	if (one == two) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
