/**
 *    Author: Nachiket Kanore
 *    Created: Monday 16 May 2022 01:18:31 AM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int ans = 1;
	int A[N];
	F0R(i, N) {
		cin >> A[i];
	}
	for (int i = 0; i < N;) {
		int j = i + 1;
		while (j < N && A[j - 1] != A[j]) {
			j++;
		}
		ans = max(ans, j - i);
		i = j;
	}
	cout << ans;
	return 0;
}
