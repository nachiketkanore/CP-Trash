/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 03:31:20 PM IST
(ツ) If you're walking down the right path and you're willing to keep walking, eventually you'll make progress.
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
	
	int n, x;
	cin >> n >> x;

	multiset<int> f;

	FOR (i,1,n) {
		int u;
		cin >> u;
		if (u < x) f.insert(x - u);
	}

	int ans = 0;

	while (true) {
		if (!sz(f)) 
			break;
		else if (sz(f) == 1) {
			ans += *f.begin();
			break;
		} else {
			int mx1 = *f.rbegin();
			f.erase(f.find(mx1));
			int mx2 = *f.rbegin();
			f.erase(f.find(mx2));
			ans += mx2;
			if (mx1 - mx2 > 0) {
				f.insert(mx1 - mx2);
			}
		}
	}
	cout << ans << "\n";
}
