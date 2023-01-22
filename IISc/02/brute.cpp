#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int mask(int u) {
	int m = 0;
	while (u) {
		m |= 1 << (u % 10);
		u /= 10;
	}
	return m;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int A[N], B[M];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		int L, R;
		cin >> L >> R;
		set<int> poss;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int val = mask(A[i]) | mask(B[j]);
				for (int x = L; x <= R; x++) {
					if (val == mask(x))
						poss.insert(x);
				}
			}
		}
		cout << poss.size() << '\n';
	}
	return 0;
}
