/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 31 January 2024 09:45:08 PM IST
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

const int MAX = 1e5, LIMIT = 2024;
int N, K, X;
int A[MAX], freq[LIMIT], nfreq[LIMIT];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> X;
	F0R(i, N) {
		cin >> A[i];
		++freq[A[i]];
	}

	while (K--) {
		int id = 1;
		F0R(val, LIMIT) if (freq[val]) {
			int odd_cnt = 0, even_cnt = 0;
			if (id & 1) {
				odd_cnt = (freq[val] + 1) / 2;
				even_cnt = freq[val] - odd_cnt;
				nfreq[val] += even_cnt;
				assert((val ^ X) < LIMIT);
				nfreq[val ^ X] += odd_cnt;
			} else {
				even_cnt = (freq[val] + 1) / 2;
				odd_cnt = freq[val] - even_cnt;
				nfreq[val] += even_cnt;
				assert((val ^ X) < LIMIT);
				nfreq[val ^ X] += odd_cnt;
			}
			id += freq[val];
		}
		memcpy(freq, nfreq, sizeof(freq));
		memset(nfreq, 0, sizeof(nfreq));
		/* F0R(val, LIMIT) {
			freq[val] = nfreq[val];
			nfreq[val] = 0;
		} */
	}

	int ans_min = MAX, ans_max = -MAX;
	F0R(val, LIMIT) if (freq[val]) {
		ans_min = min(ans_min, val);
		ans_max = max(ans_max, val);
	}
	cout << ans_max << ' ' << ans_min;
	return 0;
}
