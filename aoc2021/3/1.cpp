/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 December 2021 04:40:16 PM IST
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

template <class T>
bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int ones[100], zeros[100];

int32_t main()
{
	string S;
	int most = 0, least = 0;
	int BITS = -1;

	while (cin >> S) {
		const int N = S.size();
		if (BITS == -1)
			BITS = N;
		else {
			assert(BITS == N);
		}
		for (int i = 0; i < N; i++) {
			int bit = S[i] - '0';
			if (bit == 1) {
				ones[i]++;
			} else {
				zeros[i]++;
			}
		}
	}
	for (int i = 0; i < BITS; i++) {
		assert(ones[i] != zeros[i]);
		if (ones[i] > zeros[i]) {
			most = most * 2 + 1;
			least = least * 2 + 0;
		} else if (zeros[i] > ones[i]) {
			most = most * 2 + 0;
			least = least * 2 + 1;
		}
	}

	cout << most << ' ' << least << '\n';
	cout << most * least << '\n';
	cout << "OK\n";
}
