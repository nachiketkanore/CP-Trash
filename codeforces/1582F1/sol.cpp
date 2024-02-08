/** - saw the solution to fix the TLE
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 06:19:55 PM IST
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

const int INF = 1e9;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> min_last(512, INF);
	min_last[0] = 0;
	F0R(i, N) {
		int val;
		cin >> val;
		vector<int> min_last_next(min_last);
		F0R(curr, 512) {
			int prev = curr ^ val;
			if (min_last[prev] < val) {
				min_last_next[curr] = min(min_last_next[curr], val);
			}
		}
		min_last = min_last_next;
	}

	vector<int> ans;
	F0R(i, 512) if (min_last[i] < INF) ans.push_back(i);
	cout << sz(ans) << '\n';
	for (int x : ans)
		cout << x << ' ';

	return 0;
}
