/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 29 September 2022 08:13:04 PM IST
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
	vector<int> D(N);
	for (int& x : D)
		cin >> x;
	vector<int> A(N);
	A[0] = D[0];
	for (int i = 1; i < N; i++) {
		int choice1 = A[i - 1] - D[i];
		int choice2 = A[i - 1] + D[i];
		if (choice1 >= 0 && D[i] > 0) {
			cout << "-1\n";
			return;
		}
		A[i] = choice2;
	}
	for (int x : A) {
		cout << x << ' ';
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
