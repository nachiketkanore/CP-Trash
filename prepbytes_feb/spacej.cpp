/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 01:07:10 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 1e5 + 5, LOG = 20;

int n, L, Q, x[N], par[LOG + 1][N];

int32_t main() {
	// problem copied from: https://www.hackerrank.com/contests/code-red-s-2020/challenges/answer-the-queries-1-1/problem
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) cin >> x[i];
	cin >> L >> Q;

	FOR(i, 1, n) {
		int to = -1;
		int lo = i + 1, hi = n;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (x[mid] - x[i] <= L) {
				to = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (~to)
			par[0][i] = to;
	}

	FOR(i, 1, LOG)
	FOR(j, 1, n)
	if (par[i - 1][j])
		par[i][j] = par[i - 1][par[i - 1][j]];

	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		int ans = 0;
		for (int jump = LOG; ~jump; --jump) {
			if (a <= par[jump][a] && par[jump][a] <= b) {
				ans += 1 << jump;
				a = par[jump][a];
			}
		}
		ans += a != b;
		cout << ans << '\n';
	}
}
