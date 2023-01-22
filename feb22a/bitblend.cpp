/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 February 2022 03:55:51 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

inline int rand(int l, int r) {
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int32_t main() {
	int T = 10000;
	cin >> T;
	while (T--) {
		int N = rand(2, 200);
		cin >> N;
		int B[N], cnt[2];
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < N; i++) {
			B[i] = rand(0, 10000);
			cin >> B[i];
			B[i] %= 2;
			cnt[B[i]]++;
		}
		if (cnt[1] >= 1) {
			vector<pair<int, int>> ans;
			int got = 1e9;
			for (int start = 0; start < 2; start++) {
				vector<pair<int, int>> best;
				int A[N];
				for (int i = 0; i < N; i++)
					A[i] = B[i];
				int one_pos = -1;
				int make[N];
				for (int i = 0; i < N; i++) {
					make[i] = (start + i) % 2;
					if (A[i] == 1 && A[i] == make[i]) {
						one_pos = i;
					}
				}
				if (one_pos == -1) {
					for (int i = 0; i < N; i++) {
						if (A[i] == 1) {
							one_pos = i;
						}
					}
				}
				assert(~one_pos);
				for (int i = 0; i < N; i++) {
					if (i == one_pos)
						continue;
					if (make[i] ^ A[i]) {
						best.push_back(make_pair(i, one_pos));
						A[i] ^= 1;
					}
				}
				if (make[one_pos] ^ A[one_pos]) {
					int other_one_pos = -1;
					for (int i = 0; i < N; i++) {
						if (A[i] == 1 && i != one_pos) {
							other_one_pos = i;
							break;
						}
					}
					assert(~other_one_pos);
					assert(make[other_one_pos] == A[other_one_pos]);
					best.push_back(make_pair(one_pos, other_one_pos));
					A[one_pos] ^= A[other_one_pos];
				}
				for (int i = 0; i < N; i++) {
					assert(A[i] == make[i]);
				}
				if (got > (int)best.size()) {
					got = best.size();
					ans = best;
				}
			}
			cout << ans.size() << '\n';
			for (auto pair : ans) {
				cout << pair.first + 1 << ' ' << pair.second + 1 << '\n';
			}

		} else {
			// cout << "N = " << N << '\n';
			// for (int i = 0; i < N; i++) {
			// 	cout << B[i] << " \n"[i == N - 1];
			// }
			cout << "-1\n";
		}
	}
	return 0;
}
