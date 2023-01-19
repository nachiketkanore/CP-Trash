/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 07:11:28 PM IST
(ツ) To accomplish great things, we must dream as well as act.
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

	string s, t;
	cin >> s >> t;

	int n = sz(s);
	int ans = 0;

	for (int i = n - 1; ~i; i--) {
		if (i + sz(t) - 1 >= n)
			continue;
		string curr = s.substr(i, sz(t));
		if (curr == t) {
			++ans;
			s[i] = '#';
		}
	}

	cout << ans;
}
