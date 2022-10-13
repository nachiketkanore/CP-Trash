/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:59:46 PM IST
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
	int N;
	cin >> N;
	vector<int> A(N), ans;
	for (int& x : A) {
		cin >> x;
	}
	sort(ALL(A));
	ans.push_back(A.back());
	A.pop_back();

	int curr = ans[0];
	// see(curr);

	auto get = [&](const vector<int>& want_bits) -> int {
		for (int x : A) {
			bool have = true;
			for (int cbit : want_bits) {
				have &= x >> cbit & 1;
				if (!have)
					break;
			}
			if (have)
				return x;
		}
		return -1;
	};

	while (sz(ans) != N) {
		int start = -1;
		for (int bit = 32; bit >= 0; bit--) {
			if ((curr >> bit & 1) == 0) {
				bool found = false;
				for (int x : A) {
					if (x >> bit & 1) {
						start = bit;
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
		}
		// see(start);
		if (~start) {
			vector<int> want = { start };
			for (int bit = start - 1; bit >= 0; bit--) {
				if ((curr >> bit & 1) == 0) {
					want.push_back(bit);
					int add = get(want);
					if (~add) {
					} else {
						want.pop_back();
					}
				}
			}
			int add = get(want);
			curr |= add;
			// see(want, add);
			ans.push_back(add);
			auto it = find(ALL(A), add);
			assert(it != A.end());
			A.erase(it);
		} else {
			for (int x : A) {
				ans.push_back(x);
			}
			break;
		}
	}

	assert(sz(ans) == N);
	for (int x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
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
