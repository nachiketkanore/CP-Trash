#include "bits/stdc++.h"
using namespace std;

#define int int64_t

int N, K, A[2000], dp[2000][2001];
const int INF = 1e12;

int solve(int id, int len_rem) {
	if (len_rem == 0)
		return A[id];
	if (id == N)
		return -INF;
	int& ans = dp[id][len_rem];
	if (~ans)
		return ans;
	ans = 0;
	for (int j = id + 1; j < N; j++) {
		if (A[j] >= A[id]) {
			ans = max(ans, A[id] + solve(j, len_rem - 1));
		}
	}
	return ans;
}

bool solve(int len) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= len; j++)
			dp[i][j] = -1;
	for (int i = 0; i < N; i++) {
		int mx_sum = solve(i, len - 1);
		if (mx_sum >= K)
			return true;
	}
	return false;
}

int32_t main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int lo = 1, hi = N;
	int best = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) {
			best = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << best;
}
