/*
Author: Nachiket Kanore
Created: Sunday 10 January 2021 06:05:34 PM IST
(ツ) There is not one big cosmic meaning for all, there is only the meaning we each give to our life.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int A = 1234567;
	int B = 123456;
	int C = 1234;

	for (int a = 0;; a++)
		if (a * A <= n) {
			for (int b = 0;; b++)
				if (a * A + b * B <= n) {
					int rem = n - a * A - b * B;
					if (rem % C == 0) {
						cout << "YES\n";
						return 0;
					}
				} else
					break;
		} else
			break;

	cout << "NO\n";
}
