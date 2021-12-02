/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 02 December 2021 02:32:27 PM IST
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

int32_t main()
{
	vector<int> A;
	int x;
	while (cin >> x) {
		A.push_back(x);
	}
	vector<int> B;
	for (int i = 2; i < sz(A); i++) {
		B.push_back(A[i - 2] + A[i - 1] + A[i]);
	}
	int answer = 0;
	for (int i = 1; i < sz(B); i++) {
		answer += B[i - 1] < B[i];
	}
	cout << answer << '\n';
}
