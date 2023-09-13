/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 14 September 2023 12:50:47 AM IST
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

	int N, M, K;
	cin >> N >> M >> K;
	vector<string> A(N);
	for (auto& a : A) {
		cin >> a;
	}

	sort(A.begin(), A.end());

	string answer;

	F0R(i, K) {
		answer += A[i];
	}
	sort(answer.begin(), answer.end());

	cout << answer << '\n';

	return 0;
}
