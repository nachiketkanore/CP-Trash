/*
Author: Nachiket Kanore
Created: Thursday 22 July 2021 11:29:16 PM IST
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void test() {
	int N; cin >> N; int A[N]; for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = 1; i < N; i++) {
		A[i] += A[i-1];
	}
	cout << A[N-1] - A[0] << endl;
}

int main() {
	vector<int> chk = {2, 3, 3, 3, 1};
	reverse(chk.begin() + 3, chk.end());
	for (int x: chk) cout << x << ' '; cout << endl;
	return 0;
	int n;
	cin >> n;
	vector<int> cnt(32);
	int ans = 0;
	for (int i = 0; i < n; i++){ 
		int u;
		cin >> u;
		for (int j = 0; j < 32; j++) {
			if (u >> j & 1)
				cnt[j]++;
			ans = max(ans, cnt[j]);
		}
	}
	cout << ans << '\n';
}
