/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 22 May 2022 04:25:10 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N;
	cin >> N;
	string S;
	cin >> S;
	bool small = false, large = false, dig = false, spl = false;
	for (char ch : S) {
		if (ch >= 'a' && ch <= 'z')
			small = true;
		if (ch >= 'A' && ch <= 'Z')
			large = true;
		if (ch >= '0' && ch <= '9')
			dig = true;
		if (ch == '#' || ch == '@' || ch == '*' || ch == '&')
			spl = true;
	}
	if (!small)
		S += 'a';
	if (!large)
		S += 'A';
	if (!dig)
		S += '0';
	if (!spl)
		S += '#';
	while (sz(S) < 7)
		S += 'a';
	cout << S << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
