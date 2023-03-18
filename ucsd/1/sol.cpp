#include <bits/stdc++.h>
using namespace std;

const int _ = 200;
int n, source[_], dest[_], dp[_][_][_];

int go(int index, int rightmost_index, int remain) {
	if (remain == 0)
		return 0;
	if (index == n)
		return -1e9;

	// if (this state is visited) {
	// 	return memoized answer;
	// }
	int ans = 0;
	int union_extend = 0;

	if (rightmost_index != -1 && source[index] <= dest[rightmost_index]) { // a choice based on overlapping or not
		union_extend = max(0, dest[index] - dest[rightmost_index]);
	} else {
		union_extend = dest[index] - source[index];
	}

	// choice 1: consider index-th range in our subset
	{
		int new_rightmost_index = 0;
		if (rightmost_index == -1) {
			new_rightmost_index = index;
		} else {
			new_rightmost_index = (dest[index] > dest[rightmost_index] ? index : rightmost_index);
		}
		ans = max(ans, union_extend + go(index + 1, new_rightmost_index, remain - 1));
	}

	// choice 2: don't consider
	ans = max(ans, 0 + go(index + 1, rightmost_index, remain));

	// Memoize the answer
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = 4;
	int k = 3;
	// source[0] = 1, dest[0] = 5;
	// source[1] = 3, dest[1] = 8;
	// source[2] = 6, dest[2] = 10;
	// source[3] = 7, dest[3] = 11;
	// source[4] = 9, dest[4] = 12;
	source[0] = 1, dest[0] = 12;
	source[1] = 2, dest[1] = 9;
	source[2] = 5, dest[2] = 7;
	source[3] = 100, dest[3] = 200;
	cout << go(0, -1, k);
	return 0;
}

