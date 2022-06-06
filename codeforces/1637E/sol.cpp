/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 07 June 2022 12:49:22 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast32_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N, M;
	cin >> N >> M;

	map<int, int> freq;
	vector<pair<int, int>> bad;
	FOR(i, 1, N) {
		int u;
		cin >> u;
		freq[u]++;
		bad.push_back({ u, u });
	}

	while (M--) {
		int x, y;
		cin >> x >> y;
		bad.push_back({ x, y });
		bad.push_back({ y, x });
	}
	sort(ALL(bad));

	auto check_bad = [&](int x, int y) -> bool { return binary_search(ALL(bad), make_pair(x, y)); };

	vector<vector<int>> freq_vals(N + 1);
	set<int> freqs_;
	for (const auto [val, occ] : freq) {
		freq_vals[occ].push_back(val);
		freqs_.insert(occ);
	}

	FOR(i, 1, N) {
		sort(ALL(freq_vals[i]));
		reverse(ALL(freq_vals[i]));
	}

	vector<int> freqs(ALL(freqs_));
	long long ans = 0;
	for (int i = 0; i < sz(freqs); i++) {
		int cnt_x = freqs[i];
		for (int x : freq_vals[cnt_x]) {
			for (int j = 0; j <= i; j++) {
				int cnt_y = freqs[j];
				for (int y : freq_vals[cnt_y]) {
					if (!check_bad(x, y)) {
						ans = max(ans, 1ll * (x + y) * 1ll * (cnt_x + cnt_y));
						break;
					}
				}
			}
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
