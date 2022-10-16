/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 08:18:21 PM IST
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

const int MX = 2e5 + 5;
int N, A[MX];

void solve() {
	cin >> N;
	int have = 0;
	vector<int> take;
	FOR(i, 1, N) {
		cin >> A[i];
		int p2 = 0;
		while (A[i] % 2 == 0) {
			p2++;
			A[i] /= 2;
		}
		A[i] = p2;
		have += A[i];
		int u = i;
		int add = 0;
		while (u % 2 == 0) {
			add++;
			u /= 2;
		}
		take.push_back(add);
	}
	sort(ALL(take));
	int ans = 0;
	while (sz(take) && have < N) {
		ans++;
		have += take.back();
		take.pop_back();
	}
	if (have >= N) {
		cout << ans << '\n';
	} else {
		cout << "-1\n";
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
