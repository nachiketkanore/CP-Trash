/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 September 2023 02:58:05 PM IST
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

int lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}

void solve() {
	int N;
	string S;
	cin >> N >> S;
	S = "$" + S;
	vector<int> P(N + 1);
	FOR(i, 1, N) cin >> P[i];

	vector<bool> vis(N + 1, false);
	vector<int> first_time_equal_iters;

	FOR(start, 1, N) if (!vis[start]) {
		int u = start;
		string original;
		vector<int> cycle;
		while (!vis[u]) {
			original += S[u];
			cycle.push_back(u);
			vis[u] = true;
			u = P[u];
		}

		int start_id = 1;
		const int LEN = sz(cycle);
		int first_time_equals = -1;

		FOR(iter, 1, sz(cycle)) {
			string curr;

			FOR(id, start_id, LEN - 1) curr += S[cycle[id]];
			F0R(id, start_id) curr += S[cycle[id]];

			if (curr == original) {
				first_time_equals = iter;
				break;
			}

			start_id = (start_id + 1) % LEN;
		}

		assert(~first_time_equals);
		first_time_equal_iters.push_back(first_time_equals);
	}

	int answer = first_time_equal_iters[0];
	for (int value : first_time_equal_iters) {
		answer = lcm(answer, value);
	}
	cout << answer << '\n';
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
