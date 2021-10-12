#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int A[N], sum1 = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum1 += A[i];
	}
	int M; cin >> M;
	int B[M], sum2 = 0;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		sum2 += B[i];
	}
	if (sum1 % 2 == 0 && sum2 % 2 == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int one = sum1 - A[i] + B[j];
			int two = sum2 - B[j] + A[i];
			if (one % 2 == 0 && two % 2 == 0) {
				cout << 1;
				return 0;
			}
		}
	}
	cout << -1;
}
