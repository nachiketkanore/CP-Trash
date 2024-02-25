/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 February 2024 11:45:38 AM IST
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
	string S;
	char from, to;
	int change[26];
	F0R(i, 26) change[i] = i;
	cin >> N >> S >> Q;
	while (Q--) {
		cin >> from >> to;
		F0R(i, 26) if ((from - 'a') == change[i]) change[i] = int(to - 'a');
	}
	for (char ch : S)
		cout << char('a' + change[ch - 'a']);
	return 0;
}
