/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 03 November 2021 12:57:18 PM IST
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

const int _ = 1e7;
const int INF = 1e18;
array<int, 3> answer = { INF, -1, -1 };
int pos[_ + 1];

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

void update_answer(int val, int i, int j) {
	cmin(answer, { val, i, j });
}

int32_t main() {
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int val;
		cin >> val;
		if (pos[val]) {
			update_answer(lcm(val, val), pos[val], i);
		} else {
			pos[val] = i;
		}
	}
	FOR(g, 1, _) {
		int first = -1;
		for (int one = g; one <= _; one += g) {
			if (pos[one]) {
				if (~first) {
					update_answer(one * first / g, pos[one], pos[first]);
					break;
				} else {
					first = one;
				}
			}
		}
	}
	if (answer[1] > answer[2])
		swap(answer[1], answer[2]);
	cout << answer[1] << ' ' << answer[2] << '\n';
}
