/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 02 December 2021 02:42:33 PM IST
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
	string movement;
	int X;
	int aim = 0, hor_dist = 0, depth = 0;
	while (cin >> movement >> X) {
		if (movement == "down") {
			aim += X;
		} else if (movement == "up") {
			aim -= X;
		} else if (movement == "forward") {
			hor_dist += X;
			depth += aim * X;
		}
	}
	cout << hor_dist << ' ' << depth << '\n';
	cout << hor_dist * depth << '\n';
}
