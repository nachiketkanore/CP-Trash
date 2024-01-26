/**
 *    Author: Nachiket Kanore
 *    Created: Friday 26 January 2024 10:49:43 AM IST
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

	int N, Q;
	cin >> N >> Q;
	vector<int> B(N);
	for (int& x : B)
		cin >> x;
	while (Q--) {
		int K;
		cin >> K;
		int answer = 0;
		vector<int> A = B;

		for (int bit = 60; ~bit; --bit) {
			int ops_req = 0;
			F0R(i, N) if ((A[i] >> bit & 1) == 0) {
				int right = 0;
				F0R(b, bit + 1) right |= (1ll << b) * (A[i] >> b & 1);
				assert(right < (1ll << bit));
				ops_req += 1ll * (1ll << bit) - right;
				if (ops_req > K)
					break;
			}
			if (ops_req <= K) {
				K -= ops_req;
				answer |= 1ll << bit;
				F0R(i, N) if ((A[i] >> bit & 1) == 0) A[i] = 1ll << bit;
			}
		}

		cout << answer << endl;
	}

	return 0;
}
