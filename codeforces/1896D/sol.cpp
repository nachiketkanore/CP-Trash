/**
 *    Author: Nachiket Kanore
 *    Created: Friday 26 January 2024 11:52:27 AM IST
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

const int _ = 1e5 + 5;
int N, Q, A[_];

void solve() {
	cin >> N >> Q;
	set<int> onepos;
	int sum = 0;
	FOR(i, 1, N) {
		cin >> A[i];
		sum += A[i];
		if (A[i] == 1)
			onepos.insert(i);
	}

	auto getmaxsum = [&](int parity) -> int {
		assert(!onepos.empty());
		int L = *onepos.begin();
		int R = *onepos.rbegin();
		int maxsum = 0;
		// L+1..N
		{
			int len = N - L;
			int c1 = sz(onepos) - 1;
			int c2 = len - c1;
			int tot = c1 * 1 + c2 * 2;
			assert(tot % 2 == parity);
			maxsum = max(maxsum, tot);
		}
		// 1..R-1
		{
			int len = R - 1;
			int c1 = sz(onepos) - 1;
			int c2 = len - c1;
			int tot = c1 * 1 + c2 * 2;
			assert(tot % 2 == parity);
			maxsum = max(maxsum, tot);
		}
		return maxsum;
	};

	while (Q--) {
		int op, s, i, v;
		cin >> op;
		if (op == 1) {
			cin >> s;
			if (s % 2 == 0) {
				if (sum % 2 == 0) {
					cout << "YES\n";
				} else {
					// find max sum subarray with even parity
					int mx = getmaxsum(0);
					if (mx >= s) {
						cout << "YES\n";
					} else {
						cout << "NO\n";
					}
				}
			}
			if (s % 2 == 1) {
				if (sum % 2 == 1) {
					cout << "YES\n";
				} else {
					// find max sum subarray with odd parity
					if (onepos.empty()) {
						// all 2s
						cout << "NO\n";
					} else {
						int mx = getmaxsum(1);
						if (mx >= s) {
							cout << "YES\n";
						} else {
							cout << "NO\n";
						}
					}
				}
			}
		} else {
			cin >> i >> v;
			if (A[i] == 1 && v == 2) {
				onepos.erase(i);
				sum += 1;
			}
			if (A[i] == 2 && v == 1) {
				onepos.insert(i);
				sum -= 1;
			}
			A[i] = v;
		}
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
