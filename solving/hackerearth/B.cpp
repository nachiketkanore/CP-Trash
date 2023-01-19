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
const int N = 1000 + 5;

int dp[2][N][N];

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		F0R(i, 2) F0R(j, n) F0R(z, k + 1) dp[i][j][z] = -1;
		F0R(i, n) cin >> a[i];
		const int MOD = 1e9 + 7;
		function<int(int, int, int)> go = [&](int id, int cnt, int sum) {
			if (cnt > k)
				return int(0);
			if (id == n)
				return int(sum % 2 == 1 && cnt == k);
			int& ans = dp[sum][id][cnt];
			if (~ans)
				return ans;
			ans = 0;
			ans = (ans + go(id + 1, cnt, sum)) % MOD;
			ans = (ans + go(id + 1, cnt + 1, (sum + a[id]) % 2)) % MOD;
			return ans;
		};
		cout << go(0, 0, 0) << '\n';
	}
}
