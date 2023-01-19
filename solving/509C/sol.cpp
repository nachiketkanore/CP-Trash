/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 12:44:52 PM IST
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

// https://www.geeksforgeeks.org/smallest-number-greater-than-y-with-sum-of-digits-equal-to-x/
string helper(int d, int s) {
	string ans(d, '0');

	for (int i = d - 1; i >= 0; i--) {
		if (s >= 9) {
			ans[i] = '9';
			s -= 9;
		} else {
			char c = (char)s + '0';
			ans[i] = c;
			s = 0;
		}
	}
	return ans;
}

string findMin(int x, string y) {

	int n = y.size();
	vector<int> p(n);

	for (int i = 0; i < n; i++) {
		p[i] = y[i] - '0';
		if (i > 0)
			p[i] += p[i - 1];
	}

	for (int i = n - 1, k = 0;; i--, k++) {

		int d = 0;

		if (i >= 0)
			d = y[i] - '0';

		for (int j = d + 1; j <= 9; j++) {

			int r = (i > 0) * p[i - 1] + j;

			if (x - r >= 0 and x - r <= 9 * k) {

				string suf = helper(k, x - r);

				string pre = "";
				if (i > 0)
					pre = y.substr(0, i);

				char cur = (char)j + '0';
				pre += cur;

				return pre + suf;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	string prev = "0";

	FOR(i, 1, n) {
		int sod;
		cin >> sod;
		string ans = findMin(sod, prev);
		cout << ans << '\n';
		prev = ans;
	}
}
