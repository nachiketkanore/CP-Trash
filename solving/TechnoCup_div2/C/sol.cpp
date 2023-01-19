/*
Author: NK
Created: Sunday 25 October 2020 04:31:07 PM IST
(ツ) To climb steep hills requires a slow pace at first.
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> strs(6);
	for (int& x : strs)
		cin >> x;
	sort(strs.rbegin(), strs.rend());

	int n;
	cin >> n;

	vector<int> b(n);

	for (int& x : b)
		cin >> x;

	sort(b.begin(), b.end());

	vector<int> mat[6];

	for (int x : b) {
		cout << x << " ";
		for (int i = 0; i < 6; i++) {
			mat[i].push_back(x - strs[i]);
		}
	}
	cout << "\n";

	FOR(i, 0, 5) FOR(j, 1, n) cout << mat[i][j - 1] << "\t\n"[j == n];
}
