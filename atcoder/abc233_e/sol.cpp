/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 28 May 2022 03:50:57 PM IST
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

const int _ = 5e5 + 5;
int pref[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	cin >> S;
	const int N = S.size();

	F0R(i, N) {
		pref[i] = S[i] - '0';
		if (i > 0)
			pref[i] += pref[i - 1];
	}

	string answer;
	int carry = 0;

	for (int i = N - 1; i >= 0; --i) {
		int curr = (pref[i] + carry);
		int dig = curr % 10;
		answer += (char)(dig + '0');
		carry = curr / 10;
	}

	while (carry > 0) {
		answer += (char)(carry % 10 + '0');
		carry /= 10;
	}

	reverse(ALL(answer));
	cout << answer << '\n';

	return 0;
}
