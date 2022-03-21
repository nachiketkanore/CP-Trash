/**
 *    Author: Nachiket Kanore
 *    Created: Monday 21 March 2022 08:58:59 PM IST
**/
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, X;
		cin >> N >> X;
		int A[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A, A + N);
		set<int> check;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			check.insert(A[i]);
			check.insert(A[i] - X);
			check.insert(A[i] + X);
		}
		vector<int> chk(check.begin(), check.end());
		for (int make: chk) {
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (A[i] == make || A[i] - X == make || A[i] + X == make) {
					++cnt;
				}
			}
			ans = max(ans, cnt);
		}
		assert(ans > 0);
		cout << ans << '\n';
	}
	return 0;
}
