/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 22 October 2022 09:29:03 PM IST
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	const int INF = 1e9;
	string S, T;
	cin >> S >> T;
	if (sz(S) ^ sz(T)) {
		cout << "-1\n";
		return 0;
	}

	int cost[26][26];
	F0R(i, 26) F0R(j, 26) {
		cost[i][j] = i == j ? 0 : INF;
	}

	int M;
	cin >> M;
	while (M--) {
		char a, b;
		int w;
		cin >> a >> b >> w;
		a -= 'a';
		b -= 'a';
		cost[a][b] = min(cost[a][b], w);
	}

	F0R(k, 26) F0R(a, 26) F0R(b, 26) {
		cost[a][b] = min(cost[a][b], cost[a][k] + cost[k][b]);
	}

	string ans;
	int tot = 0;
	const int N = sz(S);
	F0R(i, N) {
		int best = INF, put = -1;
		F0R(make, 26) {
			int req = cost[S[i] - 'a'][make] + cost[T[i] - 'a'][make];
			if (req < best) {
				best = req;
				put = make;
			}
		}
		ans += (char)(put + 'a');
		tot += best;
	}

	if (tot >= INF) {
		cout << "-1\n";
	} else {
		cout << tot << '\n' << ans << '\n';
	}

	return 0;
}
