/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 February 2022 10:07:59 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int OFFSET = -3e4;

int32_t main() {
	// slow solution: O(sqrt(sum(A) * N))
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int A[N], sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			A[i] += OFFSET;
			sum += A[i];
		}
		int orig_sum = sum;
		sum = abs(sum);
		function<int(int)> max_parts = [&](int t) {
			int parts = 0, curr = 0;
			for (int i = 0; i < N; i++) {
				curr += A[i];
				if (curr == t) {
					++parts;
					curr = 0;
				}
			}
			if (parts * t == orig_sum) return parts;
			return int(0);
		};
		int k = 1;
		for (int t = 1; t * t <= sum; t++) {
			if (sum % t == 0) {
				k = max(k, max_parts(t));
				if (sum / t != t) {
					k = max(k, max_parts(sum / t));
				}
			}
		}
		cout << N - k << '\n';
	}
	return 0;
}
