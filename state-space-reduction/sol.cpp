/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 March 2023 05:15:31 PM IST
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

const int MX = 1000;
const int MOD = 1e9 + 9;
int N, X, Y, A[MX];

// i - j - k
// no need to store value of i
// store the monotonocity of A[i] -> A[j]
// either increasing or decreasing
int go(int k, int i, int j, int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (k == N)
		return x == 0 && y == 0;
	int ans = 0;
	// take A[k]
	int nx = x, ny = y;
	if (~i && ~j && A[i] > A[j] && A[j] < A[k])
		nx -= 1;
	if (~i && ~j && A[i] < A[j] && A[j] > A[k])
		ny -= 1;
	ans += go(k + 1, j, k, nx, ny);
	if (ans >= MOD)
		ans -= MOD;
	// dont take A[k]
	ans += go(k + 1, i, j, x, y);
	if (ans >= MOD)
		ans -= MOD;

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> X >> Y;
		F0R(i, N) cin >> A[i];
		cout << go(0, -1, -1, X, Y);
	}

	return 0;
}
