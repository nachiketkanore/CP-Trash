#include <iostream>
using namespace std;

int main() {
	int N, Y;
	cin >> N >> Y;
	int A[N], sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	int ans = sum;
	for (int i = 1; i < N - 1; i++) {
		int get = sum - A[i];
		get += min(A[i], Y);
		ans = min(ans, get);
	}
	for (int i = 1; i < N - 2; i++) {
		int get = sum - (A[i] + A[i + 1]);
		get += min(A[i], Y);
		get += min(A[i + 1], Y);
		ans = min(ans, get);
	}
	cout << ans << '\n';
}
