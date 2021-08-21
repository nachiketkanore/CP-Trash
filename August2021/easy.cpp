#include <bits/stdc++.h>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		const int INF = 1e9;
		int N, L, R, X, ans = 0;
		cin >> N >> L >> R >> X;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int mask = 0; mask < (1 << N); mask++) {
			int bits = __builtin_popcount(mask);
			if (bits < 2) continue;
			int mn = INF, mx = -INF, diff = 0;
			for (int i = 0; i < N; i++) {
				if (mask >> i & 1) {
					diff += A[i];
					mn = min(mn, A[i]);
					mx = max(mx, A[i]);
				}
			}
			if (L <= diff && diff <= R && mx - mn >= X) {
				++ans;
			}
		}
		cout << ans << '\n';
	}
}
