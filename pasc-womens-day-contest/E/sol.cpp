/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 09 March 2023 12:19:28 AM IST
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

const int _ = 1e5 + 5;
int N, K, M, A[_];

void solve() {
	cin >> N >> K >> M;
	FOR(i, 1, N) cin >> A[i];

	auto check_exists_for_length = [&](int len) {
		int pairs = 0, max_pairs = 0;
		unordered_map<int, int> freq;
		FOR(i, 1, len) {
			// A[i] + A[j] = K
			// A[j] = K - A[i]
			if (freq[K - A[i]] > 0) {
				pairs++;
			}
			freq[A[i]]++;
		}
		max_pairs = max(max_pairs, pairs);
		int remove_id = 1;
		FOR(i, len + 1, N) {
			int remove_val = A[remove_id];
			freq[A[remove_id]]--;
			if (freq[K - remove_val] > 0) {
				pairs--;
			}
			remove_id += 1;
			if (freq[K - A[i]] > 0) {
				pairs++;
			}
			freq[A[i]]++;
			max_pairs = max(max_pairs, pairs);
		}
		return max_pairs >= M;
	};

	int lo = 1, hi = N;
	int best = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check_exists_for_length(mid)) {
			best = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << best << '\n';
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
