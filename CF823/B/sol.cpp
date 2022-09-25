/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 September 2022 08:10:06 PM IST
**/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

void solve() {
	int N; cin >> N;
	vector<pair<int,int>> A(N);
	for (auto &it: A) { cin >> it.first; }
	for (auto &it: A) { cin >> it.second; }


	auto f = [&](long double x0) {
		long double ans = -1e18;
		for (const auto &[x, t]: A) {
			ans = max(ans, t + abs((long double)x - x0));
		}
		return ans;
	};

	int L = 0, R = 1e9;
	while (L < R) {
		int mid = (L + R) / 2;
		double f1 = f(mid);
		double f2 = f(mid + 1);
		if (f1 > f2) {
			L = mid + 1;
		} else if (f2 > f1) 
			R = mid - 1;
		else {
			break;
		}
	}
	cout << (L + R) / 2. << '\n';
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
