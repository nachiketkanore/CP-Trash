/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 17 March 2022 10:30:55 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int A[N], B[N], first = 0, second = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (A[i] == B[i])
			++first;
		for (int j = 0; j < N; j++) {
			if (i ^ j) {
				if (A[j] == B[i])
					++second;
			}
		}
	}
	cout << first << '\n' << second << '\n';
	return 0;
}
