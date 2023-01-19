/*
Author: Nachiket Kanore
Created: Sunday 18 October 2020 02:33:00 PM IST
(ツ) Courage is not the absence of fear, but simply moving on with dignity despite that fear.
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
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int mat[300][300];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		FOR(i, 1, n) FOR(j, 1, n) mat[i][j] = -1;

		FOR(i, 1, n) FOR(j, 1, n) {
			char ch;
			cin >> ch;
			mat[i][j] = (ch == '0' or ch == '1' ? ch - '0' : -1);
		}

		int one = mat[2][1], two = mat[1][2], three = mat[n][n - 1], four = mat[n - 1][n];
		vector<pair<int, int>> ans;

		if (one == two) {
			if (one == 0) {
				if (three == 0)
					ans.push_back({ n, n - 1 });
				if (four == 0)
					ans.push_back({ n - 1, n });
			} else if (one == 1) {
				if (three == 1)
					ans.push_back({ n, n - 1 });
				if (four == 1)
					ans.push_back({ n - 1, n });
			} else
				assert(false);
		} else if (three == four) {
			if (three == 0) {
				if (one == 0)
					ans.push_back({ 2, 1 });
				if (two == 0)
					ans.push_back({ 1, 2 });
			} else if (three == 1) {
				if (one == 1)
					ans.push_back({ 2, 1 });
				if (two == 1)
					ans.push_back({ 1, 2 });
			} else
				assert(false);
		} else {
			assert((one ^ two) && (three ^ four));

			if (one == 0) {
				ans.push_back({ 2, 1 });
				assert(two != 0);
			}

			if (two == 0) {
				ans.push_back({ 1, 2 });
				assert(one != 0);
			}

			if (three == 1) {
				ans.push_back({ n, n - 1 });
				assert(four != 1);
			}

			if (four == 1) {
				ans.push_back({ n - 1, n });
				assert(three != 1);
			}
		}

		assert(sz(ans) <= 2);
		cout << sz(ans) << '\n';
		for (auto it : ans) {
			cout << it.first << ' ' << it.second << '\n';
		}
	}
}
