/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 November 2022 08:20:58 PM IST
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

const int MAX = 1e5 + 5;
int freq[MAX][10];

void solve() {
	int N;
	cin >> N;
	FOR(i, 1, N + 1) F0R(ch, 10) freq[i][ch] = 0;
	string S;
	cin >> S;
	S = "$" + S;

	FOR(i, 1, N) {
		freq[i][S[i] - '0']++;
		F0R(ch, 10) {
			freq[i][ch] += freq[i - 1][ch];
		}
	}

	auto get_distinct = [&](int L, int R) {
		int ret = 0;
		F0R(ch, 10) ret += freq[R][ch] - freq[L - 1][ch] > 0;
		return ret;
	};

	auto get_max_occ = [&](int L, int R) {
		int ret = 0;
		F0R(ch, 10) ret = max(ret, freq[R][ch] - freq[L - 1][ch]);
		return ret;
	};

	int ans = 0;

	FOR(L, 1, N) {
		int curr = L;
		int d = 1;
		while (curr <= N) {
			int nxt = -1;
			int lo = curr, hi = N;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (get_distinct(L, mid) <= d) {
					nxt = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			lo = curr, hi = nxt;
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (get_max_occ(L, mid) <= get_distinct(L, mid)) {
					best = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			if (~best)
				ans += best - curr + 1;

			d++;
			curr = nxt + 1;
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
