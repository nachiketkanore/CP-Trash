/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:03:28 PM IST
(ツ) The most dangerous way to lose time is not to spend it having fun, but to spend it doing fake work. When you spend time having fun, you know you're being self-indulgent.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int NOD(int n) {
	return (!n ? 0 : 1 + NOD(n / 10));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<int> vals;

	FOR(dig,1,9) {
		int val = 0;
		FOR(t,1,4) {
			val = val * 10 + dig;
			vals.push_back(val);
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int x : vals) {
			ans += NOD(x);
			if (x == n) break;
		}
		cout << ans << '\n';
	}
}
