/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 March 2023 01:33:09 PM IST
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

const int _ = 50, INF = 1e10;
int n, m, len, mn[_], mx[_], sum[_], ans = -INF;
vector<int> arrays[_], indices;
bool done[_];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	indices.resize(m);
	F0R(i, n) {
		cin >> len;
		arrays[i].resize(len);
		for (int& x : arrays[i])
			cin >> x;
		sum[i] = accumulate(ALL(arrays[i]), int(0));
		mn[i] = INF;
		mx[i] = -INF;
	}
	auto update = [&](int idx) {
		if (done[idx])
			return;
		int min_pref = INF, P = 0;
		for (int x : arrays[idx]) {
			P += x;
			ans = max({ ans, P, P - min_pref });
			min_pref = min(min_pref, P);
		}
		done[idx] = true;
	};
	for (int& id : indices) {
		cin >> id;
		--id;
		update(id);
	}
	F0R(i, n) {
		FOR(j, 1, sz(arrays[i]) - 1) arrays[i][j] += arrays[i][j - 1];
		mn[i] = *min_element(ALL(arrays[i]));
		mx[i] = *max_element(ALL(arrays[i]));
	}
	int min_pref = INF, P = 0;
	for (int id : indices) {

		int get = mx[id] + P;
		ans = max(ans, get - min_pref);
		ans = max(ans, get);
		// ans = max(ans, P);

		min_pref = min(min_pref, mn[id] + P);
		P += sum[id];
	}
	cout << ans << '\n';

	return 0;
}
