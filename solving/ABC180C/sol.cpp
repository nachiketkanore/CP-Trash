/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 03:09:43 PM IST
(ツ) One secret of success in life is for a man to be ready for his opportunity when it comes.
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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> ans;
	for (int d = 1; d * d <= n; d++) if (n % d == 0) {
		ans.push_back(d);
		if (n/d!=d) ans.push_back(n/d);
	}
	sort(ans.begin(), ans.end());
	for (int x : ans)
		cout << x << "\n";
}
