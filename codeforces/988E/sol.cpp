/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 31 May 2022 04:16:51 PM IST
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

	string S;
	cin >> S;
	const int N = S.size();
	const int INF = 1e18;
	int ans = INF;

	auto check = [](const string& T) { return T[0] == '0'; };

	// taken from geeksforgeeks
	auto compute = [](string A, string B) {
		const int size = A.size();
		int i = 0, j = 0;
		int ret = 0;

		while (i < size) {
			j = i;

			while (A[j] != B[i]) {
				j += 1;
			}

			while (i < j) {
				swap(A[j], A[j - 1]);
				j -= 1;
				ret += 1;
			}
			i += 1;
		}
		return ret;
	};

	auto process = [&](int i, int j) {
		// send S[i] @ N - 1
		// send S[j] @ N - 2
		string T = S;
		for (int id = i; id < N - 1; id++) {
			swap(T[id], T[id + 1]);
		}
		if (i < j)
			--j;
		for (int id = j; id < N - 2; id++) {
			swap(T[id], T[id + 1]);
		}

		if (T[0] == '0') {
			int pos = -1;
			for (int id = 0; id < N - 2; id++) {
				if (T[id] != '0') {
					pos = id;
					break;
				}
			}
			if (pos == -1)
				return INF;
			for (int id = pos - 1; id >= 0; id--) {
				swap(T[id], T[id + 1]);
			}
			assert(T[0] != '0');
		}

		int val = stoll(T);
		if (val % 25 == 0)
			return compute(S, T);
		return INF;
	};

	F0R(i, N) F0R(j, N) {
		if (i == j)
			continue;
		ans = min(ans, process(i, j));
	}

	if (ans >= INF)
		ans = -1;
	cout << ans << '\n';

	return 0;
}
