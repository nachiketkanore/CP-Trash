/*
Author: NK
Created: Saturday 17 October 2020 06:33:37 PM IST
(ツ) The only difference between your abilities and others is the ability to put yourself in their shoes and actually try.
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

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> whoLeft(n, -1), whoRight(n, -1);
		vector<bool> left(n, false), right(n, false);

		for (int i = 0; i < n; i++) {
			whoRight[i] = (i + 1) % n;
			whoLeft[i] = (i == 0 ? n - 1 : i - 1);
			if (s[i] == '>') {
				right[i] = true;
			} else if (s[i] == '<') {
				left[whoRight[i]] = true;
			} else {
				right[i] = true;
				left[whoRight[i]] = true;
			}
		}

		bool cycle1 = true, cycle2 = true;

		for (int i = 0; i < n; i++) {
			cycle1 &= right[i];
			cycle2 &= left[i];
		}

		bool cycle = cycle2 || cycle1;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (left[i] && right[i]) {
				ans += cycle || left[whoRight[i]] || right[whoLeft[i]];
			} else if (left[i]) {
				ans += cycle || right[whoLeft[i]];
			} else if (right[i]) {
				ans += cycle || left[whoRight[i]];
			}
		}
		cout << ans << '\n';
	}
}
