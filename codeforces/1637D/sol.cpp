/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 13 September 2023 07:05:09 PM IST
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

const int _ = 100;
int N, A[_], B[_], dp[_][_ * _ + 1];

int go(int id, int prefa, int prefb) {
	if (id == N)
		return 0;
	int& ans = dp[id][prefa];
	if (~ans)
		return ans;
	ans = 0;

	int c1 = A[id] * prefa + B[id] * prefb + go(id + 1, prefa + A[id], prefb + B[id]);
	int c2 = B[id] * prefa + A[id] * prefb + go(id + 1, prefa + B[id], prefb + A[id]);

	ans = min(c1, c2);
	return ans;
}

void solve() {
	int ans = 0;
	cin >> N;
	F0R(i, N) {
		cin >> A[i];
		ans += (N - 1) * A[i] * A[i];
	}
	F0R(i, N) {
		cin >> B[i];
		ans += (N - 1) * B[i] * B[i];
	}

	memset(dp, -1, sizeof(dp));
	ans += go(0, 0, 0) << 1;
	cout << ans << '\n';

	// wrong greedy approach
	/* auto compute = [&]() {
		int sum = 0;
		F0R(i, N) F0R(j, N) if (i < j) sum += (A[i] + A[j]) * (A[i] + A[j]) + (B[i] + B[j]) * (B[i] + B[j]);
		return sum;
	};

	int ans = compute();

	while (true) {
		int which = -1;
		int best = ans;

		F0R(i, N) {
			swap(A[i], B[i]);
			int get = compute();
			if (get < ans) {
				if (get < best) {
					best = get;
					which = i;
				}
			}
			swap(A[i], B[i]);
		}

		if (best == ans)
			break;
		swap(A[which], B[which]);
		assert(best < ans);
		ans = best;
	}

	cout << ans << '\n'; */
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

/*
 * for pairs i < j
 * (Ai + Aj)^2 = Ai^2 + Aj^2 + 2.Ai.Aj +
 * (Bi + Bj)^2 = Bi^2 + Bj^2 + 2.Bi.Bj
 *
 * total pairs = nC2 = n * (n - 1) / 2 = P
 *
 * total cost = P * (sum of squares of A and B) = constant
 *  + 2 * (Ai.Aj + Bi.Bj) = other
 * other = 2 * (sum of Ai * (sum - Ai) + Bi * (sum - Bi))
 *
 * */
