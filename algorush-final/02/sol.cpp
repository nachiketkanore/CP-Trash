/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 12:20:06 PM IST
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
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	for (int& x : A) {
		cin >> x;
	}
	int i = 0, round = 1;
	vector<int> vals;
	while (i < N) {
		int j = i + round - 1;
		if (j >= N)
			break;
		int add = 0;
		FOR(id, i, j) {
			add += A[id];
		}
		vals.push_back(add);
		i += round;
		round++;
	}
	int half = sz(vals) / 2;
	vector<int> one, two;
	F0R(i, sz(vals)) {
		if (i < half) {
			one.push_back(vals[i]);
		} else {
			two.push_back(vals[i]);
		}
	}

	vector<int> sa, sb;
	int ans = 0;

	F0R(mask, 1 << sz(one)) {
		int sum = 0;
		F0R(i, sz(one)) if (mask >> i & 1) {
			sum += one[i];
		}
		sa.push_back(sum);
		if (sum <= X) {
			ans = max(ans, sum);
		}
	}
	F0R(mask, 1 << sz(two)) {
		int sum = 0;
		F0R(i, sz(two)) if (mask >> i & 1) {
			sum += two[i];
		}
		sb.push_back(sum);
		if (sum <= X) {
			ans = max(ans, sum);
		}
	}
	sort(ALL(sa));
	sort(ALL(sb));

	for (int x : sa) {
		if (x > X)
			continue;
		int rem = X - x;
		int id = upper_bound(ALL(sb), rem) - sb.begin();

		FOR(j, id - 2, id + 2) {
			if (j >= 0 && j < sz(sb)) {
				int y = sb[j];
				if (x + y <= X) {
					ans = max(ans, x + y);
				}
			}
		}
	}

	assert(ans <= X);
	cout << ans << '\n';
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
