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

int dp[2][1010][1010];

int32_t main() {
	auto solve = [&]() {
		int n, m;
		cin >> n >> m;
		vector<int> V(n), P(n);
		F0R(i, n) cin >> V[i] >> P[i];
		memset(dp, -1, sizeof(dp));

		function<int(int, int, int)> go = [&](int id, int rem, int used) {
			if (rem < 0 || used > 1)
				return -inf;
			if (id == n)
				return int(0);
			int& ans = dp[used][id][rem];
			if (~ans)
				return ans;
			ans = -inf;
			cmax(ans, V[id] + go(id + 1, rem - P[id], used));
			cmax(ans, V[id] + go(id + 1, rem - P[id] / 2, used + 1));
			cmax(ans, go(id + 1, rem, used));
			return ans;
		};

		int ans = go(0, m, 0);
		cout << ans << '\n';
	};
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
