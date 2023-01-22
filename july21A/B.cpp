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
const int N = 1e5 + 5;

int n, a[N], pref[N], suff[N];

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int sum = 0;
		cin >> n;
		FOR(i, 0, n + 1) {
			pref[i] = suff[i] = 0;
		}
		FOR(i, 1, n) {
			cin >> a[i];
			sum += a[i];
			pref[i] = suff[i] = a[i];
		}
		if (n == 1) {
			cout << "1\n";
			continue;
		}
		FOR(i, 2, n) pref[i] = __gcd(pref[i], pref[i - 1]);
		for (int i = n - 1; i >= 1; i--)
			suff[i] = __gcd(suff[i], suff[i + 1]);

		int ans = inf;

		FOR(i, 1, n) {
			int g = __gcd(pref[i - 1], suff[i + 1]);
			int UP = sum - a[i] + g;
			assert(UP % g == 0);
			cmin(ans, UP / g);
		}

		cout << ans << '\n';
	}
}
