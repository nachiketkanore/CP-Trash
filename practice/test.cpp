#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, sum = 0;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}
		cout << "Sum of elements = " << sum << "\n";
	}
}
