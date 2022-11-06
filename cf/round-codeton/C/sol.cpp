/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 06 November 2022 08:36:36 PM IST
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
	vector<int> A(N + 1), B(N + 1), pref(N + 5), suff(N + 5);
	FOR(i, 1, N) {
		char ch;
		cin >> ch;
		A[i] = ch - '0';
	}
	FOR(i, 1, N) {
		char ch;
		cin >> ch;
		B[i] = ch - '0';
	}
	vector<pair<int, int>> ans;
	FOR(i, 1, N) {
		if (A[i] == 1) {
			A[i] = 0;
			pref[i - 1] += 1;
			suff[i + 1] += 1;
			ans.push_back({ i, i });
		}
	}
	FOR(i, 2, N) {
		suff[i] += suff[i - 1];
	}
	for (int i = N - 1; i >= 1; i--) {
		pref[i] += pref[i + 1];
	}

	bool ok1 = true, ok0 = true;

	FOR(i, 1, N) {
		int flipped = (pref[i] + suff[i]) % 2;
		if (flipped) {
			B[i] ^= 1;
		}
		ok1 &= B[i] == 1;
		ok0 &= B[i] == 0;
	}

	if (ok1) {
		FOR(i, 1, N) assert(A[i] == 0);
		FOR(i, 1, N) assert(B[i] == 1);
		ans.push_back({ N, N });
		ans.push_back({ 1, N - 1 });
		ans.push_back({ 1, N });
	} else if (ok0) {
	} else {
		cout << "NO\n";
		return;
	}

	assert(sz(ans) < N + 5);
	cout << "YES\n" << sz(ans) << '\n';
	for (auto [L, R] : ans) {
		cout << L << ' ' << R << '\n';
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
