/*
Author: Nachiket Kanore
Created: Friday 16 October 2020 04:26:22 PM IST
(ツ) Learn wisdom from the ways of a seedling. A seedling which is never hardened off through stressful situations will never become a strong productive plant.
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

int SOD(int n) {
	return (!n ? 0 : n % 10 + SOD(n / 10));
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;	cin >> n;
	vector<int> ans;

	FOR(val,n-100,n+100) if (val > 0) {
		if (val + SOD(val) == n) {
			ans.push_back(val);
		}
	}

	sort(ans.begin(), ans.end());
	cout << sz(ans) << '\n';
	for (int a : ans) cout << a << ' ';
}
