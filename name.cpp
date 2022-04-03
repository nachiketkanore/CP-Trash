/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 03 April 2022 11:41:12 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	string a, b, c;
	cin >> a >> b >> c;
	const int mn	  = min({ sz(a), sz(b), sz(c) });
	auto generate_all = [&](const string& S) {
		set<string> ret;
		const int N = S.size();
		for (int mask = 1; mask < (1 << N); mask++) {
			string add;
			for (int i = 0; i < N; i++) {
				if (mask >> i & 1) {
					add += S[i];
				}
			}
			if (sz(add) > mn)
				continue;
			ret.insert(add);
		}
		return ret;
	};
	const set<string> A = generate_all(a), B = generate_all(b), C = generate_all(c);
	int ans = 0;
	for (auto& x : A) {
		if (B.count(x) && C.count(x)) {
			ans = max(ans, sz(x));
		}
	}
	for (auto& x : B) {
		if (A.count(x) && C.count(x))
			ans = max(ans, sz(x));
	}
	for (auto& x : C) {
		if (A.count(x) && B.count(x))
			ans = max(ans, sz(x));
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}
