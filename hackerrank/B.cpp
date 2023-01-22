#include <bits/stdc++.h>

#define pb push_back
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

const int inf = 1e9;
const int N = 101, OFF = 2e5 + 5;

int n, a[N], dp[N][OFF << 1];

int go(int id, int sum) {
	if (id > n)
		return sum == 0 ? 1 : 0;
	int& ans = dp[id][OFF + sum];
	if (~ans)
		return ans;
	ans = 0;
	ans |= go(id + 1, sum + a[id]);
	ans |= go(id + 1, sum - a[id]);
	return ans;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	int already = go(1, 0);
	if (already) {
		cout << 1 << '\n';
		int all = inf;
		FOR(i, 1, n) {
			int u = a[i];
			int cnt = 0;
			while (u % 2 == 0)
				++cnt, u >>= 1;
			cmin(all, cnt);
		}
		FOR(i, 1, n) {
			int rem = all;
			while (rem--)
				a[i] >>= 1;
		}
		FOR(i, 1, n) if (a[i] & 1) {
			cout << i << '\n';
			break;
		}
	} else
		cout << 0 << '\n';
}
