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

int n, a[N], pos[N + 1];
int spf[N + 1];
vector<int> pf[N + 1];

int32_t main() {
	FOR(i, 2, N) if (!spf[i]) for (int j = i; j <= N; j += i) {
		if (!spf[j])
			spf[j] = i;
	}
	FOR(i, 2, N) {
		int u = i;
		while (u ^ 1) {
			int p = spf[u];
			while (u % p == 0)
				u /= p;
			pf[i].push_back(p);
		}
	}

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 1, n) cin >> a[i];

		int best = -1;

		F0R(rep, 2) {
			int ans = 0;

			for (int i = n; i >= 1; i--) {
				int j = n + 1;
				for (int p : pf[a[i]]) {
					if (pos[p] > 0)
						cmin(j, pos[p]);
				}

				cmax(ans, j - i);

				for (int p : pf[a[i]]) {
					pos[p] = i;
				}
			}
			if (ans <= 1)
				ans = -1;
			cmax(best, ans);

			FOR(i, 1, n) for (int p : pf[a[i]]) pos[p] = 0;
		}

		cout << best << '\n';
	}
}
