/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 08:47:26 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int N = 2e5;
int spf[N + 1];

void SPF() {
	for (int i = 2; i <= N; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j <= N; j += i) {
				if (spf[j] == 0)
					spf[j] = i;
			}
		}
	}
}

map<int, int> PF(int u) {
	map<int, int> ret;
	while (u > 1) {
		int p = spf[u];
		int alpha = 0;
		while (u % p == 0) {
			alpha++;
			u /= p;
		}
		ret[p] = alpha;
	}
	return ret;
}

map<int, int> PF_big(int u) {
	map<int, int> ret;
	for (int d = 2; d * d <= u; d++) {
		if (u % d == 0) {
			int cnt = 0;
			while (u % d == 0) {
				u /= d;
				++cnt;
			}
			ret[d] = cnt;
		}
	}
	if (u > 1) {
		ret[u] = 1;
	}
	return ret;
}

void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	auto pf_ab = PF_big(a * b);
	FOR(x, a + 1, c) {
		auto pf_x = PF(x);
		int y = 1;
		for (auto [p, alpha] : pf_ab) {
			int have = pf_x[p];
			if (have >= alpha) {
			} else {
				int add = alpha - have;
				while (add--)
					y *= p;
			}
		}
		int k = b / y + 1;
		// see(x, y, k);
		y *= k;
		if (b < y && y <= d) {
			assert((x * y) % (a * b) == 0);
			cout << "YES\n";
			// cout << x << " " << y << '\n';
			return;
		}
	}
	cout << "-1 -1\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	SPF();

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
