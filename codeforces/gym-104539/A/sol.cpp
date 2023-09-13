/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 14 September 2023 12:42:59 AM IST
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
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;

	int id = S.find('.');

	int after = sz(S) - id - 1;
	int D = 1;
	while (after--) {
		D *= 10;
	}

	S = S.substr(2);

	int N = stoll(S);
	// see(N, D);

	int d = __gcd(N, D);

	cout << "YES\n";
	cout << N / d << ' ' << D / d << '\n';
	return 0;
}
