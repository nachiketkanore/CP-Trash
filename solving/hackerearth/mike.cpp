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
const int N = 2e5 + 5;

vector<int> ind[N];
int spf[N + 1], a[N], n;

void pre() {
	FOR(i, 2, N) {
		if (!spf[i]) {
			for (int j = i; j <= N; j += i) {
				if (!spf[j])
					spf[j] = i;
			}
		}
	}
}

int32_t main() {
	pre();
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		int u = a[i];
		while (u ^ 1) {
			int p = spf[u];
			ind[p].push_back(i);
			while (u % p == 0)
				u /= p;
		}
	}
	FOR(i, 1, n) {
		int u = a[i];
		int best = -1, dist = inf;
		while (u ^ 1) {
			int p = spf[u];
			int id = lower_bound(ALL(ind[p]), i) - ind[p].begin();
			const int m = sz(ind[p]);
			FOR(j, id - 2, id + 2) if (j >= 0 && j < m) {
				if (ind[p][j] == i)
					continue;
				int gdist = abs(ind[p][j] - i);
				if (gdist == dist)
					cmin(best, ind[p][j]);
				else if (gdist < dist) {
					best = ind[p][j];
					cmin(dist, gdist);
				}
			}
			while (u % p == 0)
				u /= p;
		}
		cout << best << " \n"[i == n];
	}
}
