/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 23 July 2022 12:30:28 AM IST
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
	int A[N], B[N];
	bool taken[N];
	F0R(i, N) taken[i] = false;
	F0R(i, N) cin >> A[i], B[i] = A[i];
	sort(B, B + N);

	vector<int> first, second;

	int j = 0;
	F0R(i, N) {
		while (true) {
			if (j == N)
				break;
			if (A[j] == B[i])
				break;
			if (!taken[j])
				second.push_back(A[j]);
			j++;
		}
		if (j < N && A[j] == B[i]) {
			first.push_back(A[j]);
			taken[j] = true;
		}
	}
	for (int x : second) {
		first.push_back(x);
	}
	bool sorted = true;
	F0R(i, N) if (i) sorted &= first[i - 1] <= first[i];
	if (sorted) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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
