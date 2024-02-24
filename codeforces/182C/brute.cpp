/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 February 2024 12:04:26 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int long long
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 1e5 + 5;
int N, K, L, A[_];

int negatives(vector<int> neg, int k) {
	sort(ALL(neg));
	for (int& x : neg) {
		if (k > 0)
			x *= -1, --k;
	}
	return accumulate(ALL(neg), 0ll);
}

int positives(vector<int> pos, int k) {
	sort(ALL(pos));
	reverse(ALL(pos));
	for (int& x : pos) {
		if (k > 0)
			x *= -1, --k;
	}
	return accumulate(ALL(pos), 0ll);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	FOR(i, 1, N) cin >> A[i];
	cin >> K;

	int ans = 0;
	// trying the naive approach
	FOR(i, 1, N) {
		if (i + L - 1 <= N) {
			vector<int> pos, neg;
			int tot = 0, possum = 0, negsum = 0;
			FOR(j, i, i + L - 1) {
				tot += A[j];
				if (A[j] >= 0) {
					pos.push_back(A[j]);
					possum += A[j];
				} else {
					neg.push_back(A[j]);
					negsum += A[j];
				}
			}
			int best = abs(tot);
			best = max(best, abs(possum + negatives(neg, K)));
			best = max(best, abs(negsum + positives(pos, K)));

			ans = max(ans, best);
		}
	}
	cout << ans;

	return 0;
}
