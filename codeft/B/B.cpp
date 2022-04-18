/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 09:09:52 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int PermuteTheArray(int A[], int n) {

	int arr[n];

	// Store the indices of the
	// elements present in A[].
	for (int i = 0; i < n; i++) {
		arr[A[i] - 1] = i;
	}

	// Store the maximum and
	// minimum index of the
	// elements from 1 to i.
	int mini = n, maxi = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {

		// Update maxi and mini, to
		// store minimum and maximum
		// index for permutation
		// of elements from 1 to i+1
		mini = min(mini, arr[i]);
		maxi = max(maxi, arr[i]);

		// If difference between maxi
		// and mini is equal to i
		if (maxi - mini == i)

			// Increase count
			count++;
	}

	// Return final count
	return count;
}

bool checkPrime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void solve() {
	int N;
	cin >> N;
	if (N <= 3) {
		cout << N << '\n';
		return;
	}
	if (checkPrime(N))
		cout << 3 << '\n';
	else
		cout << 2 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/* FOR(N, 1, 50) {
		int P[N + 1];
		FOR(j, 1, N) P[j] = j;

		for (int i = 2; i <= N; ++i) {
			vector<int> temp;
			for (int j = i; j <= N; j += i) {
				temp.push_back(P[j]);
			}
			int k = temp.size() - 1;
			for (int j = i; j <= N; j += i) {
				P[j] = temp[k];
				k--;
			}
		}
		int perm[N];
		F0R(i, N) perm[i] = P[i + 1];
		// cout << PermuteTheArray(perm, N) << '\n';
		int ans = PermuteTheArray(perm, N);
		cout << "N = " << N << ": " << ans << '\n';
		assert(ans <= 3);
		// FOR(i, 1, N) {
		// 	cout << P[i] << " \n"[i == N];
		// }
	} */
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
