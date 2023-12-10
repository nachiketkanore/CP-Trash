#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int numberOfGoodPartitions(vector<int> A) {
		const int N = A.size();

		map<int, int> last_id;
		for (int i = 0; i < N; i++)
			last_id[A[i]] = i;

		int id = 0;
		int parts = 0;
		while (id < N) {
			int j = id;
			int go_till = last_id[A[j]];

			while (j < go_till) {
				j++;
				if (j < N) {
					go_till = max(go_till, last_id[A[j]]);
				}
			}
			id = go_till + 1;
			++parts;
		}

		const int MOD = 1e9 + 7;
		int ways = 1;
		for (int i = 1; i < parts; i++) {
			ways = ways * 2 % MOD;
		}
		return ways;
	}
};

int32_t main() {
	Solution sol;
	cout << sol.numberOfGoodPartitions({ 1, 2, 3, 4 }) << endl;
	cout << sol.numberOfGoodPartitions({ 1, 1, 1, 1 }) << endl;
	cout << sol.numberOfGoodPartitions({ 1, 2, 1, 3 }) << endl;
}

