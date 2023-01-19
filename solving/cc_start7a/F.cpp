/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 July 2021 04:48:49 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

string S;
int n;
int dp[2][60][3][31];

int go(int id, bool small_taken, int sid, int bsum) {
	if (id == n)
		return bsum;
	int hash = sid == -1 ? 2 : sid % 2;
	int& ans = dp[small_taken][id][hash][bsum];
	if (~ans)
		return ans;
	ans = 0;

	int from = 0, to = 1;
	if (!small_taken)
		to = S[id] - '0';

	FOR(dig, from, to) {
		int get = 0;
		if (sid >= 0) {
			if ((id - sid) % 2 == 0)
				get = dig;
		} else if (dig == 1)
			get = 1;
		int nsid = -1;
		if (sid >= 0)
			nsid = sid;
		else if (dig == 1)
			nsid = id;
		ans += go(id + 1, small_taken || (dig < S[id] - '0'), nsid, bsum + get);
	}
	return ans;
}

int get_value(int K) {
	S.clear();
	while (K) {
		S += (char)('0' + (K % 2));
		K >>= 1;
	}
	reverse(ALL(S));
	n = sz(S);
	memset(dp, -1, sizeof(dp));

	return go(0, 0, -1, 0);
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int lo = 1, hi = 1e12;
		int ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int value = get_value(mid);
			if (value >= N)
				ans = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		assert(~ans);
		cout << ans << '\n';
	}
}
