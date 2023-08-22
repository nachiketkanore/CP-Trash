#include "bits/stdc++.h"
using namespace std;

class Solution {
	public:
	int freq[3][100001];

	int takeCharacters(string S, int K) {
		const int N = S.size();
		S = "$" + S;
		int ans = 1e9;
		for (int i = 1; i <= N; i++) {
			freq[S[i] - 'a'][i]++;
			for (int ch = 0; ch < 3; ch++) {
				freq[ch][i] += freq[ch][i - 1];
			}
		}
		auto check = [&](int l, int r) {
			bool ok = true;
			for (int ch = 0; ch < 3; ch++) {
				int taken = freq[ch][N] - (freq[ch][r] - freq[ch][l - 1]);
				ok &= taken >= K;
			}
			if (ok) {
				// [l, r] remains, rest is taken
				ans = min(ans, N - (r - l + 1));
			}
			return ok;
		};
		// case left: take all
		if (freq[0][N] >= K && freq[1][N] >= K && freq[2][N] >= K) {
			ans = min(ans, N);
		}
		for (int L = 1; L <= N; L++) {
			check(1, L);
			check(L, N);
			int lo = L, hi = N;
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (check(L, mid)) {
					lo = mid + 1;
					best = mid;
				} else {
					hi = mid - 1;
				}
			}
			if (~best) {
				check(L, best);
			}
		}
		if (ans == 1e9) {
			ans = -1;
		}
		return ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solution s;
	cout << s.takeCharacters("bcca", 1);
	return 0;
}

