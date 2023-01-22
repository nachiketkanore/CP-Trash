#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int A[N], B[M];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + M);
	if (A[N - 1] > B[M - 1]) {
		cout << "0";
		return 0;
	}
}
