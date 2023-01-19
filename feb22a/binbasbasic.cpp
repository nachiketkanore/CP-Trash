/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 February 2022 03:15:04 PM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		string S;
		cin >> N >> K >> S;
		auto get_bad = [&]() {
			int bad = 0;
			int L = 0, R = N - 1;
			while (L < R) {
				bad += S[L++] != S[R--];
			}
			return bad;
		};
		int bad = get_bad();
		if (N % 2 == 0) {
			if (K < bad) {
				cout << "NO\n";
			} else {
				K -= bad;
				if (K % 2 == 0) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		} else {
			if (K < bad) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
		}
	}
	return 0;
}
