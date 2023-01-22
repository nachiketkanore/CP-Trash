/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 17 October 2021 02:56:19 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N, L, R;
		cin >> N >> L >> R;
		int A[N];
		vector<int> elements[10];
		F0R(i, N) {
			cin >> A[i];
			int len = 0;
			for (int u = A[i]; u; u /= 10)
				++len;
			elements[len].push_back(A[i]);
		}
		F0R(j, 10) {
			sort(ALL(elements[j]));
		}
		auto solve = [&](int X) -> int {
			int ans = 0;
			F0R(i, N) {
				for (int len = 1, ten = 10; len <= 9; len++, ten *= 10) {
					int aj = X - A[i] * ten;
					ans += upper_bound(ALL(elements[len]), aj) - elements[len].begin();
				}
			}
			return ans;
		};
		cout << solve(R) - solve(L - 1) << '\n';
	}
}
