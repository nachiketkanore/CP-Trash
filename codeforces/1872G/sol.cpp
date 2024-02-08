/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 12:55:36 PM IST
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
	int A[N + 1], pref_prod[N + 1], pref_sum[N + 1];
	pref_prod[0] = 1;
	pref_sum[0] = 0;

	__int128_t prod = 1;
	const __int128_t MAX = 1e15;
	bool large_product = false;

	FOR(i, 1, N) {
		cin >> A[i];
		pref_prod[i] = pref_prod[i - 1] * A[i];
		pref_sum[i] = pref_sum[i - 1] + A[i];

		if (!large_product) {
			prod *= A[i];
			if (prod > MAX)
				large_product = true;
		}
	}

	auto get_range_sum = [&](int l, int r) {
		if (1 <= l && l <= r && r <= N) {
			return pref_sum[r] - pref_sum[l - 1];
		}
		return int(0);
	};
	auto get_range_product = [&](int l, int r) {
		if (1 <= l && l <= r && r <= N) {
			return pref_prod[r] / pref_prod[l - 1];
		}
		return int(1);
	};

	if (large_product) {
		int l = 1, r = N;
		while (A[l] == 1)
			++l;
		while (A[r] == 1)
			--r;
		cout << l << ' ' << r << '\n';
	} else {
		vector<int> non_one_pos;
		int best_sum = 0, ans_l = -1, ans_r = -1;

		FOR(i, 1, N) if (A[i] ^ 1) non_one_pos.push_back(i);

		if (!non_one_pos.empty()) {
			for (int l : non_one_pos) {
				for (int r : non_one_pos) {
					if (l <= r) {
						int get_sum = get_range_sum(1, l - 1) + get_range_product(l, r) + get_range_sum(r + 1, N);
						if (get_sum > best_sum) {
							best_sum = get_sum;
							ans_l = l, ans_r = r;
						}
					}
				}
			}
			assert(~ans_l && ~ans_r);
			cout << ans_l << ' ' << ans_r << '\n';
		} else {
			cout << "1 1\n";
		}
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
