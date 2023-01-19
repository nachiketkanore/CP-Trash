/**
 *    Author: Nachiket Kanore
 *    Created: Friday 12 November 2021 11:45:44 AM IST
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
	int A, B;
	cin >> A >> B;
	auto get_divisors = [](int N) {
		vector<int> ret;
		for (int i = 1; i * i <= N; i++) {
			if (N % i == 0) {
				ret.push_back(i);
				if (N / i != i)
					ret.push_back(N / i);
			}
		}
		return ret;
	};
	vector<int> dA = get_divisors(A), dB = get_divisors(B);
	sort(ALL(dA));
	sort(ALL(dB));
	int ans = 0;
	for (int d : dA) {
		if (binary_search(ALL(dB), d))
			++ans;
	}
	cout << ans << '\n';
}
