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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		F0R(i, n) cin >> a[i];

		function<int(int, int, int, int)> go = [&](int id, int done, int sid, int prev) {
			if (done == k)
				return int(0);
			if (id == n)
				return -inf;
			int ans = -inf;

			if (prev) {
				int c1 = go(id, done + 1, sid + 1, 0);
				int c2 = sid * a[id] + go(id + 1, done, sid, 1);
				int c3 = go(id + 1, done + 1, sid + 1, 0);
				ans = max({ ans, c1, c2, c3 });
			} else {
				int c1 = sid * a[id] + go(id + 1, done, sid, 1);
				int c2 = go(id + 1, done, sid, 0);
				ans = max({ ans, c1, c2 });
			}
			return ans;
		};

		int ans = go(0, 0, 1, 0);
		cmax(ans, go(0, 0, 1, 1));
		cout << ans << '\n';
	}
}
