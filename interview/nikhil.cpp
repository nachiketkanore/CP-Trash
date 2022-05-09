#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	int A[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	int L = lower_bound(A, A + N, X) - A;
	int R = upper_bound(A, A + N, X) - A - 1;
	cout << L << ' ' << R << '\n';
	return 0;
}
