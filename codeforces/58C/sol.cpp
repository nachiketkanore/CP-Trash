/** - saw the solution
 *    Author: Nachiket Kanore
 *    Created: Saturday 24 February 2024 11:25:59 AM IST
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

	int N;
	cin >> N;
	int A[N];
	F0R(i, N) cin >> A[i];
	int L = 0, R = N - 1, idx = 1;
	map<int, int> counter;
	while (L <= R) {
		counter[A[L] - idx]++;
		if (L ^ R)
			counter[A[R] - idx]++;
		L++, R--, idx++;
	}
	int ans = N;
	for (auto [k, v] : counter) {
		if (k >= 0) {
			ans = min(ans, N - v);
		}
	}
	cout << ans;

	return 0;
}
