/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 08 June 2022 11:03:47 PM IST
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

const int _ = 2000;
const int MAX = 5000;
int N, A[_], sum_cnt[MAX];
int sum_pair_cnt[2 * MAX];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) cin >> A[i];
	sort(A, A + N);

	F0R(i, N) F0R(j, i) sum_cnt[A[i] - A[j]]++;

	F0R(first, MAX) {
		F0R(second, MAX) {
			sum_pair_cnt[first + second] += sum_cnt[first] * sum_cnt[second];
		}
	}

	F0R(i, 2 * MAX) sum_pair_cnt[i] += i ? sum_pair_cnt[i - 1] : 0;

	int good = 0;

	F0R(j, N) {
		F0R(i, N) {
			int diff = A[j] - A[i];
			good += diff - 1 >= 0 ? sum_pair_cnt[diff - 1] : 0;
		}
	}

	int tot = pow(N * (N - 1) / 2, 3);

	cout << fixed << setprecision(10) << 1. * good / tot << '\n';

	return 0;
}
