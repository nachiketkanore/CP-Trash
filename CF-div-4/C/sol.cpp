/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:48:29 PM IST
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
	const string RED = string(8, 'R');
	const string BLUE = string(8, 'B');
	vector<string> cols(8);
	bool done = false;
	F0R(i, 8) {
		string S;
		cin >> S;
		assert(sz(S) == 8);
		if (S == RED) {
			if (!done)
				cout << "R\n";
			done = true;
		}
		F0R(j, 8) {
			cols[j].push_back(S[j]);
		}
		// see(cols);
	}
	if (done)
		return;

	F0R(j, 8) {
		// see(cols[j]);
		if (cols[j] == BLUE) {
			cout << "B\n";
			return;
		}
	}

	assert(0);
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
