/** - saw the editorial
 *    Author: Nachiket Kanore
 *    Created: Wednesday 31 January 2024 06:37:55 PM IST
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

	int N, M;
	cin >> N >> M;
	int A[N], B[M];
	int xA = 0, xB = 0;
	F0R(i, N) cin >> A[i], xA ^= A[i];
	F0R(i, M) cin >> B[i], xB ^= B[i];

	if (xA == xB) {
		cout << "YES\n";
		F0R(i, N) {
			F0R(j, M) {
				if (i == 0 && j == 0) {
					int ans = A[0];
					FOR(id, 1, M - 1) ans ^= B[id];
					cout << ans;
				} else if (i == 0) {
					cout << B[j];
				} else if (j == 0) {
					cout << A[i];
				} else {
					cout << 0;
				}
				cout << " \n"[j == M - 1];
			}
		}
	} else {
		cout << "NO\n";
	}

	return 0;
}
