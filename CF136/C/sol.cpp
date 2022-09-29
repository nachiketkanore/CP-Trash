/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 29 September 2022 09:11:26 PM IST
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

int N;

int go(int rem, set<int> A, set<int> B, int got) {
	if (got > N / 2) return 0;
	int m1 = A.size() >= 2 ? *A.begin() : 0;
	int m2 = A.size() >= 2 ? *A.rbegin() : 0;
	if (rem == 0) {
		if (got != N / 2) return 0;
		return *A.rbegin() > *B.rbegin();
	}
	int ans = 0;
	set<int> nA = A; nA.insert(rem);
	ans += go(rem - 1, nA, B, got + 1);

	set<int> nB = B; nB.insert(rem);
	ans += go(rem - 1, A, nB, got);

	return ans;
}

void solve() {
	cin >> N;
	set<int> f;
	cout << go(N, f, f, 0) << '\n';
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
