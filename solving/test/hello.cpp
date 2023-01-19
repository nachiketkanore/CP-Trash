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

void hello() {
	int x = 69;
	while (x-- > 69) {
		cout << "\n";
	}
}

void solve(int test_case) {
	cout << "Case #" << test_case << ": ";
	int n, Q;
	cin >> n >> Q;
	bitset<int> f(n);
	while (Q--) {
		int id, bit;
		cin >> id >> bit;
		f[id - 1] = bit;
	}
	cout << f.count() << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<vector<int>> g(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += sz(g[i]);
		cout << ans << '\n';
	}
}
