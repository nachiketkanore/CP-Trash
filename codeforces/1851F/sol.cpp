/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 07:49:39 PM IST
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

int N, K, X;

int go(int bit, vector<int> A) {
	if (bit < 0)
		return 0;
	int ans = go(bit - 1, A);
	// make this bit 1 in x
	vector<int> unset_A;
	for (int a : A) {
		if ((a >> bit & 1) == 0) {
			unset_A.push_back(a);
		}
	}
	int c1 = 0;
	if (sz(unset_A) >= 2) {
		c1 = (1 << bit) + go(bit - 1, unset_A);
		ans = max(ans, c1);
	}
	// make this bit 0 in x
	vector<int> set_A;
	for (int a : A) {
		if (a >> bit & 1) {
			set_A.push_back(a);
		}
	}
	int c2 = 0;
	if (sz(set_A) >= 2) {
		c2 = (1 << bit) + go(bit - 1, set_A);
		ans = max(ans, c2);
	}
	if (c1 > c2) {
		X |= 1 << bit;
	}
	return ans;
}

void solve() {
	X = 0;
	cin >> N >> K;
	vector<int> A(N);
	for (int& a : A)
		cin >> a;
	int best_ans = go(K, A);
	see(X, best_ans);
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
