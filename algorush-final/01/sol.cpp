/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 12:51:41 PM IST
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

const int _ = 2e5 + 5;
const int LOG = 35;
int N, M;
int nxt[LOG + 1][_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> nxt[0][i];
	}

	FOR(j, 1, LOG) {
		FOR(i, 1, N) {
			nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
		}
	}

	while (M--) {
		int from, K;
		cin >> from >> K;

		F0R(bit, LOG) {
			if (K >> bit & 1) {
				from = nxt[bit][from];
			}
		}
		cout << from << '\n';
	}

	return 0;
}
