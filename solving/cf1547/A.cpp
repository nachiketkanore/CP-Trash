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
		int xA, yA, xB, yB, xC, yC;
		cin >> xA >> yA >> xB >> yB >> xC >> yC;
		int ans = abs(xA - xB) + abs(yA - yB);
		auto inside = [&](int lo, int hi, int x) {
			if (lo > hi)
				swap(lo, hi);
			return lo <= x && x <= hi;
		};
		if ((xA == xB && xB == xC && inside(yA, yB, yC)) || (yA == yB && yB == yC && inside(xA, xB, xC)))
			ans += 2;
		cout << ans << '\n';
	}
}
