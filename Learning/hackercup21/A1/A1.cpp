/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 29 August 2021 02:56:58 PM IST
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

const int INF = 1e9;

bool is_vowel(const char ch) {
	return ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U';
}

void solve() {
	string S;
	cin >> S;
	const int N = S.size();
	int ans = INF;
	for (char make = 'A'; make <= 'Z'; make++) {
		int req = 0;
		F0R(i, N) {
			if (make == S[i])
				continue;
			bool first = is_vowel(make);
			bool second = is_vowel(S[i]);
			if (first ^ second)
				++req;
			else
				req += 2;
		}
		cmin(ans, req);
	}
	assert(ans ^ INF);
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
