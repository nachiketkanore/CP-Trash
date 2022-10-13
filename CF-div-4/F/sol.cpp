/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:28:20 PM IST
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

void solve() {
	int Q;
	cin >> Q;
	int alen = 1, blen = 1;
	int fa[26] = {}, fb[26] = {};
	fa[0] = fb[0] = 1;
	while (Q--) {
		int type, k;
		string add;
		cin >> type >> k >> add;
		if (type == 1) {
			for (char ch : add) {
				fa[ch - 'a'] += k;
			}
			alen += k * sz(add);
		} else {
			for (char ch : add) {
				fb[ch - 'a'] += k;
			}
			blen += k * sz(add);
		}
		int cha = 0, chb = 25;
		while (fa[cha] == 0)
			cha++;
		while (fb[chb] == 0)
			chb--;
		if (cha < chb) {
			cout << "YES\n";
			continue;
		}
		if (cha > chb) {
			cout << "NO\n";
			continue;
		}
		if (fa[cha] < fb[chb]) {
			int others = alen - fa[cha];
			cout << (others > 0 ? "NO\n" : "YES\n");
			continue;
		}
		if (fa[cha] > fb[chb]) {
			cout << "NO\n";
			continue;
		}
		// fa[cha] == fb[chb]
		int oa = alen - fa[cha];
		int ob = blen - fb[chb];
		if (oa == 0 && ob == 0) {
			cout << "NO\n";
			continue;
		} else if (oa == 0 && ob != 0) {
			cout << "YES\n";
			continue;
		} else if (oa != 0 && ob == 0) {
			cout << "NO\n";
			continue;
		} else {
			cout << "NO\n";
			continue;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
