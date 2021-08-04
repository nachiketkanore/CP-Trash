/*
Author: NK
Created: Saturday 17 October 2020 07:52:20 PM IST
(ツ) Faith in oneself is the best and safest course.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
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
	
	int n, k;
	cin >> n >> k;
	multiset<int> f;

	FOR(i,1,n) {
		int u;
		cin >> u;
		f.insert(u);
	}

	while (sz(f) != k) {
		int last = *f.rbegin();
		f.erase(f.find(last));
		int one = last >> 1;
		int two = last - one;
		f.insert(one);
		f.insert(two);
	}

	int ans = 0;
	for (int x : f) ans += x * x;
		cout << ans << '\n';
}
