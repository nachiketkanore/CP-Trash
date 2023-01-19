#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	do {
		bool ok = true;
		for (int i = 1; i < N; i++) {
			ok &= __gcd(A[i], A[i - 1]) > 1;
		}
		if (ok) {
			cout << "FAILED\n";
			for (int i = 0; i < N; i++) {
				cout << A[i] << " \n"[i == N - 1];
			}
			return 0;
		}
	} while (next_permutation(A, A + N));
	return 0;
}
