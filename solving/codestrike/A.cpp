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
const int N = 1e6 + 5;

int n, a[N], pref[N], suff[N], ans;

int32_t main() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		pref[i] = 1;
		if (a[i] == a[i - 1])
			pref[i] += pref[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		suff[i] = 1;
		if (a[i] == a[i + 1])
			suff[i] += suff[i + 1];
	}
	FOR(i, 2, n) {
		if (a[i - 1] ^ a[i]) {
			int left = pref[i - 1];
			int right = suff[i];
			cmax(ans, 2 * min(left, right));
		}
	}
	cout << ans;
}
