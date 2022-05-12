/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, M;
	cin >> N >> M;
	string S[N];
	int ans = 1e9;
	auto get_cost = [](char one, char two) {
		int best = 1e9;
		for (char make = 'a'; make <= 'z'; make++) {
			int cost = abs(one - make) + abs(two - make);
			best = min(best, cost);
		}
		return best;
	};
	auto solve = [&](int i, int j) {
		int ret = 0;
		assert(sz(S[i]) == M);
		assert(sz(S[j]) == M);
		F0R(id, M) {
			ret += get_cost(S[i][id], S[j][id]);
		}
		return ret;
	};
	F0R(i, N) {
		cin >> S[i];
		F0R(j, i) {
			ans = min(ans, solve(i, j));
			ans = min(ans, solve(j, i));
		}
	}
	cout << ans << '\n';
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
