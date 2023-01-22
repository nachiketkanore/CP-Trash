#include "bits/stdc++.h"
using namespace std;

#define int int64_t

int MSBPosition(int N) {
	int msb_p = -1;
	while (N) {
		N = N >> 1;
		msb_p++;
	}
	return msb_p;
}

int findBitwiseOR(int L, int R) {
	if (L == R)
		return L;
	int res = 0;

	int msb_p1 = MSBPosition(L);

	int msb_p2 = MSBPosition(R);

	while (msb_p1 == msb_p2) {
		int res_val = (1 << msb_p1);

		res += res_val;

		L -= res_val;
		R -= res_val;

		msb_p1 = MSBPosition(L);
		msb_p2 = MSBPosition(R);
	}
	msb_p1 = max(msb_p1, msb_p2);

	for (int i = msb_p1; i >= 0; i--) {
		int res_val = (1 << i);
		res += res_val;
	}
	return res;
}
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sol = 0;
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		int best = findBitwiseOR(1, N);
		int lo = 1, hi = N;
		int ans = 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (findBitwiseOR(mid, N) == best) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		sol += ans;
	}
	cout << sol;

	return 0;
}
