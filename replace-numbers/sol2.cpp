/**
 *    Author: Nachiket Kanore
 *    Created: Monday 16 May 2022 01:06:39 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

constexpr int N = 5e5 + 1;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	vector<int> op(q), x(q), y(q);
	for (int i = 0; i < q; i++) {
		cin >> op[i] >> x[i];
		if (op[i] == 2) {
			cin >> y[i];
		}
	}

	vector<int> ans;
	vector<int> f(N);
	iota(f.begin(), f.end(), 0);
	for (int i = q - 1; i >= 0; i--) {
		if (op[i] == 1) {
			ans.push_back(f[x[i]]);
		} else {
			f[x[i]] = f[y[i]];
		}
	}

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < int(ans.size()); i++) {
		cout << ans[i] << " \n"[i == int(ans.size()) - 1];
	}

	return 0;
}
