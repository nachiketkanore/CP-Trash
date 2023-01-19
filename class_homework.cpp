/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 April 2022 04:33:11 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

bool ok(const string& S) {
	if (S == "0")
		return true;
	if (S[0] == '0')
		return false;
	long long val = stoll(S);
	return val <= 1e12;
}

void solve() {
	string S;
	cin >> S;
	const int N = sz(S);
	long long ans = -1;
	FOR(i, 0, N - 4) {
		FOR(j, i + 1, N - 3) {
			FOR(k, j + 1, N - 2) {
				// l ends at N - 1 always
				int len1 = i + 1;
				int len2 = j - i;
				int len3 = k - j;
				int len4 = N - 1 - k;
				assert(len1 > 0 && len2 > 0 && len3 > 0 && len4 > 0);
				string A = S.substr(0, len1);
				string B = S.substr(i + 1, len2);
				string C = S.substr(j + 1, len3);
				string D = S.substr(k + 1, len4);
				if (ok(A) && ok(B) && ok(C) && ok(D)) {
					ans = max(ans, stoll(A) + stoll(B) + stoll(C) + stoll(D));
				}
			}
		}
	}
	if (~ans)
		cout << ans << '\n';
	else
		cout << "unlucky\n";
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
