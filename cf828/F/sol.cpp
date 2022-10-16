/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 16 October 2022 09:14:03 PM IST
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
	int N = 10;
	int A[N];
	F0R(i, N) A[i] = i;
	random_shuffle(A, A + N);
	F0R(i, N) {
		cout << A[i] << " \n"[i == N - 1];
	}

	F0R(L, N) {
		vector<int> elem, func;
		bool have[100] = { false };
		int mex = 0;

		for (int R = L; R < N; R++) {
			have[A[R]] = true;
			while (have[mex])
				++mex;
			elem.push_back(A[R]);
			sort(ALL(elem));
			int med = elem[(sz(elem) - 1) / 2];
			func.push_back(mex > med);
			// see(elem, mex, med);
		}
		see(func);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	srand(time(nullptr));

	F0R(chk, 5) solve();

	// int T;
	// cin >> T;
	//
	// while (T--) {
	// 	solve();
	// }

	return 0;
}
