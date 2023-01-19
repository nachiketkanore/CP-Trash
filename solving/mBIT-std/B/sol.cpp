/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 01:25:41 PM IST
(ツ) No act of kindness, no matter how small, is ever wasted.
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

	string s;
	while (cin >> s) {
		const int n = s.size();
		string ans;
		s += "######";

		for (int i = 0; i < n;) {
			int j = i;
			while (j < n && s[j] == s[i])
				++j;
			j--;
			int len = j - i + 1;
			if (len == 2) {
				ans.push_back(s[i]);
			} else {
				FOR(id, i, j) ans.push_back(s[i]);
			}
			i = j + 1;
		}
		cout << ans << " ";
	}
}
