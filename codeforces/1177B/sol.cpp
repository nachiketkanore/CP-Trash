/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 31 January 2024 06:48:18 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, digit, count;
	cin >> K;

	for (digit = 1, count = 9;; digit++, count *= 10) {
		int total_digits = digit * count;
		if (total_digits <= K) {
			K -= total_digits;
			if (K == 0) {
				cout << 9;
				return 0;
			}
		} else {
			break;
		}
	}

	int start = powl(10, digit - 1);
	int end = powl(10, digit) - 1;
	assert(K > 0);

	int best = -1;
	int lo = start, hi = end;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int total_digits = (mid - start + 1) * digit;
		if (total_digits < K) {
			best = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	if (best == -1) {
		cout << to_string(start)[K - 1];
	} else {
		K -= (best - start + 1) * digit;
		cout << to_string(best + 1)[K - 1];
	}

	return 0;
}
