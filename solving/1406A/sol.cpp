/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:19:21 PM IST
(ツ) Consider that not only do negative thoughts and emotions destroy our experience of peace, they also undermine our health.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		multiset<int> all;
		FOR (i,1,n) {
			int u;	cin >> u;
			all.insert(u);
		}
		int ans = 0;

		{
			int id = 0;
			while (all.count(id)) {
				all.erase(all.find(id));
				id++;
			}
			ans += id;
		}

		{
			int id = 0;
			while (all.count(id)) {
				all.erase(all.find(id));
				id++;
			}
			ans += id;
		}
		cout << ans << "\n";
	}
}
