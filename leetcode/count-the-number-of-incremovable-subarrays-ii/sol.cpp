/**
 *    Author: Nachiket Kanore
 *    Created: Monday 25 December 2023 01:00:32 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

class Solution {
	public:
	long long incremovableSubarrayCount(vector<int>& A) {
		const int N = A.size();
		vector<bool> okpref(N, false), oksuff(N, false);
		okpref[0] = oksuff[N - 1] = true;
		int HI = 0;
		for (int i = 1; i < N; i++) {
			if (A[i - 1] < A[i]) {
				okpref[i] = true;
				HI = i;
			} else
				break;
		}
		for (int i = N - 2; i >= 0; i--) {
			if (A[i] < A[i + 1]) {
				oksuff[i] = true;
			} else
				break;
		}
		long long ans = 0;
		for (int j = 0; j < N; j++)
			if (oksuff[j]) {
				int lo = 0, hi = HI;
				if (hi > j - 2) {
					hi = j - 2;
				}
				int best = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					if (A[mid] < A[j]) {
						best = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				if (~best) {
					ans += best + 1;
				} else {
					ans += 1;
				}
			}
		for (int i = 0; i < N; i++) {
			if (okpref[i])
				++ans;
		}
		return ans + 1;
	}
};

int32_t main() {
	vector<int> A = { 1, 2, 3, 4 };
	Solution solution;
	cout << solution.incremovableSubarrayCount(A) << endl;
	A = { 6, 5, 7, 8 };
	cout << solution.incremovableSubarrayCount(A) << endl;
	A = { 8, 7, 6, 6 };
	cout << solution.incremovableSubarrayCount(A) << endl;

	return 0;
}
