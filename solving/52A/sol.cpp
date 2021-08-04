/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 07:50:12 PM IST
(ツ) I would maintain that thanks are the highest form of thought, and that gratitude is happiness doubled by wonder.
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

	vector<int> cnt(4, 0);

	int ans = inf;

	FOR(i,1,n) {
		int val;
		cin >> val;
		cnt[val]++;
	}

	FOR(one,1,3) {
		FOR(two,one+1,3) {
			ans = min(ans, cnt[one] + cnt[two]);
		}
	}

	cout << ans << "\n";
}
