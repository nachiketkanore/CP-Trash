#include <bits/stdc++.h>

#define int int64_t
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

const int inf = 1e18;
const int N = 5e5 + 5;

int set_bits(int v) {
	int ret = 0;
	while (v > 0) {
		ret += v & 1;
		v >>= 1;
	}
	return ret;
}

int dp[32][32][32][5];

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		c = -c;
		int abits = set_bits(a);
		int bbits = set_bits(b);
		string C;
		while (c) {
			C += (char)('0' + (c & 1));
			c >>= 1;
		}
		memset(dp, -1, sizeof(dp));
		function<int(int, int, int, int)> go = [&](int bit, int arem, int brem, int carry) {
			if (arem < 0 || brem < 0)
				return int(0);
			if (bit == sz(C)) {
				if (arem == 0 && brem == 0 && carry == 0)
					return int(1);
				return int(0);
			}
			int& ans = dp[bit][arem][brem][carry];
			if (~ans)
				return ans;
			ans = 0;
			int want = C[bit] - '0';
			F0R(one, 2) {
				F0R(two, 2) {
					int curr = (one + two + carry) % 2;
					if (curr ^ want)
						continue;
					int ncarry = (one + two + carry) / 2;
					ans += go(bit + 1, arem - one, brem - two, ncarry);
				}
			}
			return ans;
		};

		int ans = go(0, abits, bbits, 0);
		cout << ans << '\n';
	}
}
