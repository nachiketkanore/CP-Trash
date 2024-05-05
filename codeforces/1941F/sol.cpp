/**
 *    Author: Nachiket Kanore
 *    Created: Monday 06 May 2024 12:09:25 AM IST
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

const int _ = 2e5 + 5;
int N, M, K, A[_], D[_], F[_];

void solve() {
	cin >> N >> M >> K;
	F0R(i, N) cin >> A[i];
	F0R(i, M) cin >> D[i];
	F0R(i, K) cin >> F[i];
	sort(F, F + K);

	vector<int> diffs;
	F0R(i, N - 1) diffs.push_back(A[i + 1] - A[i]);
	sort(ALL(diffs));

	if (count(ALL(diffs), diffs.back()) > 1) {
		cout << diffs.back() << '\n';
	} else {
		int L, R;
		F0R(i, N - 1) if (A[i + 1] - A[i] == diffs.back()) {
			L = A[i], R = A[i + 1];
			break;
		}

		int answer = diffs.back();

		int mid = (L + R) / 2;
		FOR(check, mid - 1, mid + 1) {
			// now find the closest value of val:`D[i] + F[j]` to `check`
			F0R(i, M) {
				int idx = lower_bound(F, F + K, check - D[i]) - F;
				FOR(j, idx - 1, idx + 1) if (j >= 0 && j < K) {
					int val = D[i] + F[j];
					if (L <= val && val <= R) {
						int part1 = val - L, part2 = R - val;
						int final_max = sz(diffs) > 1 ? diffs[sz(diffs) - 2] : 0;
						final_max = max(final_max, part1);
						final_max = max(final_max, part2);
						answer = min(answer, final_max);
					}
				}
			}
		}
		cout << answer << '\n';
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
