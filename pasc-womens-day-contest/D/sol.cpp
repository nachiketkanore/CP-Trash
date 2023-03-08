/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 09 March 2023 12:03:08 AM IST
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

const int _ = 1e5 + 5;
int N, R, S;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> R >> S;
	int have = 0;
	vector<pair<int, int>> info(N);
	for (auto& [a, b] : info) {
		cin >> a >> b;
		have += a;
		swap(a, b);
	}
	sort(ALL(info));
	// see(have);

	int assignments = 0;

	for (auto [b, a] : info) {
		int remain = S - have;
		if (remain < 0)
			break;
		int allowed = R - a;
		int can_take = min(allowed, remain);
		assignments += can_take * b;
		have += can_take;
	}

	if (have >= S) {
		cout << assignments << '\n';
	} else {
		cout << "-1\n";
	}

	return 0;
}
