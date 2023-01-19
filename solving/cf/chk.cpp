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
const int N = 505;

int hello() {
	int n;
	cin >> n;

	int x;
	cin >> x;

	int xn;
	cin >> xn;
}

vector<pair<int, int>> g[N * N];
int dp[N * N][21];

int32_t main() {
	memset(dp, -1, sizeof(dp));
	int n, m, k;
	cin >> n >> m >> k;
	auto node = [&](int i, int j) { return (i - 1) * m + j; };
	FOR(i, 1, n) {
		FOR(j, 1, m - 1) {
			int w;
			cin >> w;
			int u = node(i, j), v = node(i, j + 1);
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
		}
	}
	FOR(i, 1, n - 1) {
		FOR(j, 1, m) {
			int w;
			cin >> w;
			int u = node(i, j), v = node(i + 1, j);
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
		}
	}

	function<int(int, int)> go = [&](int u, int rem) {
		if (rem == 0)
			return int(0);
		int& ans = dp[u][rem];
		if (~ans)
			return ans;
		ans = inf;
		for (auto [v, w] : g[u]) {
			cmin(ans, w + go(v, rem - 1));
		}
		return ans;
	};

	FOR(i, 1, n) {
		FOR(j, 1, m) {
			int u = node(i, j);
			if (k % 2)
				cout << -1;
			else
				cout << 2 * go(u, k / 2);
			cout << ' ';
		}
		cout << '\n';
	}
}
