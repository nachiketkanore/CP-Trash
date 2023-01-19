/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 05 February 2022 02:21:55 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int INF = 1e9;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N <= 500) {
			int A[N + 1];
			memset(A, 0, sizeof(A));
			for (int i = 1; i <= N; i++) {
				cin >> A[i];
				A[i] += A[i - 1];
			}

			function<int(int, int)> go = [&](int from, int each) {
				if (from == N + 1)
					return int(0);
				int ans = INF;
				for (int to = from; to <= N; to++) {
					if (each == A[to] - A[from - 1])
						ans = min(ans, to - from + go(to + 1, each));
				}
				return ans;
			};

			int ans = N - 1;
			for (int i = 1; i <= N; i++) {
				int req = (i - 1) + go(i + 1, A[i]);
				ans = min(ans, req);
			}
			cout << ans << '\n';
		} else {
			int A[N];
			for (int i = 0; i < N; i++) {
				cin >> A[i];
			}
			int k = 1;
			for (int rep = 0; rep < 2; rep++) {
				int each = 0;
				for (int i = 0; i < N; i++) {
					each += A[i];
					if (true) {
						int parts = 1;
						int curr = 0;
						bool complete = false;
						for (int j = i + 1; j < N; j++) {
							curr += A[j];
							complete = false;
							if (curr == each) {
								++parts;
								curr = 0;
								complete = true;
							}
						}
						// see(each, complete);
						if (complete) {
							// see("here");
							// see(i, each, parts);
							if (parts > k) {
								k = parts;
							}
						}
					}
				}
				reverse(A, A + N);
			}
			cout << (N - k) << '\n';
		}
	}
	return 0;
}
