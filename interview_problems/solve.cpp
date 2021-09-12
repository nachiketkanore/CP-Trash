#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int D;
	cin >> D;
	D %= N;
	for (int i = D; i < N; i++)
		cout << A[i] << ' ';
	for (int i = 0; i < D; i++)
		cout << A[i] << ' ';
	cout << '\n';
}
