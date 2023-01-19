#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(NULL));
	int T = 10;
	cout << T << '\n';
	while (T--) {
		int N = rand() % 15 + 2, K = N / 2;
		cout << N << ' ' << K << '\n';
		for (int i = 0; i < N; i++) {
			int val = rand() % 1214 + 1;
			if (i == K - 1)
				cout << abs(val) << ' ';
			else {
				if (rand() % 10 < 5)
					cout << -val << ' ';
				else
					cout << val << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
