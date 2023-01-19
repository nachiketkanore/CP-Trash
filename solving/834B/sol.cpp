/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 06:14:10 PM IST
(ツ) You have power over your mind, not outside events. Realize this, and you will find strength.
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

const int N = 1e6 + 5, inf = 1e18;

int n, k, f[30][N];
string s;

bool isFirst(char ch, int id) {
	return f[ch - 'A'][id - 1] == 0;
}

bool isLast(char ch, int id) {
	return (f[ch - 'A'][n] - f[ch - 'A'][id]) == 0;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s;
	s = " " + s;

	FOR(i, 1, n) {
		f[s[i] - 'A'][i]++;
		FOR(j, 0, 25) {
			f[j][i] += f[j][i - 1];
		}
	}

	int open = 0;

	for (int i = 1; i <= n; i++) {
		if (isFirst(s[i], i))
			open++;
		if (open > k) {
			cout << "YES\n";
			return 0;
		}
		if (isLast(s[i], i))
			open--;
	}

	cout << "NO\n";
}
