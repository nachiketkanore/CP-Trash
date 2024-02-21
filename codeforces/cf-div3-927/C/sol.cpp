/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 05:55:16 PM IST
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

const int _ = 2e5 + 5;
int N, M, A[_];

void solve() {
	cin >> N >> M;
	FOR(i, 1, N) cin >> A[i];
	int L = 1, R = N;
	string S;
	cin >> S;
	for (char ch : S) {
		if (ch == 'L')
			++L;
		else
			--R;
	}
	reverse(ALL(S));
	int prod = 1;
	vector<int> results;
	for (char ch : S) {
		if (ch == 'L') {
			--L;
			prod = prod * A[L] % M;
		} else {
			++R;
			prod = prod * A[R] % M;
		}
		results.push_back(prod);
	}
	reverse(ALL(results));
	for (int result : results) {
		cout << result << ' ';
	}
	cout << '\n';
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
