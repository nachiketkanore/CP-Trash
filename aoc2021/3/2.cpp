/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 December 2021 04:52:06 PM IST
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

int calculate_O2(vector<string> vals)
{
	const int M = vals[0].size();
	for (int bit = 0; bit < M && sz(vals) != 1; bit++) {
		int ones = 0, zeros = 0;
		const int N = vals.size();
		for (int i = 0; i < N; i++) {
			if (vals[i][bit] == '1')
				ones++;
			else
				zeros++;
		}
		char keep;
		if (ones >= zeros) {
			keep = '1';
		} else {
			keep = '0';
		}
		vector<string> n_vals;
		for (int i = 0; i < N; i++) {
			if (vals[i][bit] == keep) {
				n_vals.push_back(vals[i]);
			}
		}
		vals = n_vals;
		/* for (auto val : vals) { */
		/* 	cout << val << ' '; */
		/* } */
		/* cout << '\n'; */
	}
	assert(sz(vals) == 1);
	int ans = 0;
	for (char ch : vals[0]) {
		ans = ans * 2 + (ch - '0');
	}
	return ans;
}

int calculate_CO2(vector<string> vals)
{
	const int M = vals[0].size();
	for (int bit = 0; bit < M && sz(vals) != 1; bit++) {
		int ones = 0, zeros = 0;
		const int N = vals.size();
		for (int i = 0; i < N; i++) {
			if (vals[i][bit] == '1')
				ones++;
			else
				zeros++;
		}
		char keep;
		if (zeros <= ones) {
			keep = '0';
		} else {
			keep = '1';
		}
		vector<string> n_vals;
		for (int i = 0; i < N; i++) {
			if (vals[i][bit] == keep) {
				n_vals.push_back(vals[i]);
			}
		}
		vals = n_vals;
		/* for (auto val : vals) { */
		/* 	cout << val << ' '; */
		/* } */
		/* cout << '\n'; */
	}
	assert(sz(vals) == 1);
	int ans = 0;
	for (char ch : vals[0]) {
		ans = ans * 2 + (ch - '0');
	}
	return ans;
}

int32_t main()
{
	string S;
	vector<string> vals;
	while (cin >> S) {
		vals.push_back(S);
	}
	int O2 = calculate_O2(vals);
	int CO2 = calculate_CO2(vals);
	cout << O2 << ' ' << CO2 << '\n';
	cout << O2 * CO2 << '\n';
}
