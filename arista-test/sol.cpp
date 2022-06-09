#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool solve(string S) {
	const int N = S.size();
	int mx[2] = { 0 };

	for (char search = '0'; search <= '1'; search++) {
		int cnt = 0;
		int idx = search - '0';
		for (int i = 0; i < N; i++) {
			if (S[i] == search) {
				++cnt;
				mx[idx] = max(mx[idx], cnt);
			} else {
				mx[idx] = max(mx[idx], cnt);
				cnt = 0;
			}
		}
	}
	return mx[0] > mx[1];
}

// Implement minStack that supports Push() Pop() and GetMin() in O(1) time.

// S = [10, 20, 5, 4, 2] --> 2
// S = [10, 20, 5, 4] --> 4
// S = [10, 20, 5] --> 5
// S = [10, 20] --> 10

// S = [4, 5, 2]

// S = [4] min = 4
// S = [4, 5] min = 4
// S = [4, 5, 2] min = 2

// min_top[4] = 4
// min_top[5] = 4
// min_top[5] = min(5, min_top[4])
// min_top[2] = 2
// pop
// S = [4, 5] min = 4

// S = [3, 2, 1] -> 1
// S = [3, 2] -> 2
// S = [3] -> 3
//

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout << (solve("011100") ? "TRUE" : "FALSE") << '\n';
	cout << (solve("110000") ? "TRUE" : "FALSE") << '\n';
	cout << (solve("01010110101010111110000000") ? "TRUE" : "FALSE") << '\n';

	return 0;
}

