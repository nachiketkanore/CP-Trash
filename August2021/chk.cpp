#include <bits/stdc++.h>
#define int int64_t
using namespace std;

string bin(int u) {
	string ret;
	while (u > 0) {
		ret.push_back((char)((u % 2) + '0'));
		u /= 2;
	}
	reverse(ret.begin(), ret.end());
	assert(ret.size());
	return ret;
}

const int N = 66;
int dp[2][2][N][N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int L, R, k;
		cin >> L >> R >> k;
		array<int, 3> chk = { L, R, k };
		string A = bin(L), B = bin(R);
		assert(A.size() <= B.size());
		while (A.size() < B.size())
			A = "0" + A;
		const int n = A.size();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int l = 0; l <= n; l++)
					for (int bits = 0; bits <= k; bits++)
						dp[i][j][bits][l] = -1;
		bool ans = false;

		function<bool(int, int, int, int)> go = [&](int pos, bool bigA, bool smallB, int bits) {
			if (bits < 0)
				return false;
			if (pos >= n)
				return bits == 0;

			int& ans = dp[bigA][smallB][bits][pos];
			if (~ans)
				return bool(ans);
			ans = 0;

			for (int i = 0; i < 2; i++) {
				if (!bigA && i < A[pos] - '0')
					continue;
				if (!smallB && i > B[pos] - '0')
					continue;

				ans |= go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), bits - i);
				if (ans)
					break;
			}
			return bool(ans);
		};

		vector<int> ans_bin;

		function<void(int, int, int, int)> trace = [&](int pos, bool bigA, bool smallB, int bits) {
			if (pos >= n) {
				assert(bits == 0);
				return;
			}

			for (int i = 0; i < 2; i++) {
				if (!bigA && i < A[pos] - '0')
					continue;
				if (!smallB && i > B[pos] - '0')
					continue;

				if (go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), bits - i)) {
					ans_bin.push_back(i);
					trace(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), bits - i);
					return;
				}
			}
		};

		for (int i = 0; i < 2; i++) {
			if (i < A[0] - '0')
				continue;
			if (i > B[0] - '0')
				continue;
			ans |= go(1, i > A[0] - '0', i < B[0] - '0', k - i);
			if (ans) {
				ans_bin = { i };
				trace(1, i > A[0] - '0', i < B[0] - '0', k - i);
				int p2 = 1, my_ans = 0;
				while (ans_bin.size()) {
					if (ans_bin.back())
						my_ans += p2;
					ans_bin.pop_back();
					p2 *= 2;
				}
				cout << my_ans << '\n';
				break;
			}
		}
		if (!ans) {
			cout << "-1\n";
		}
	}
	return 0;
}
