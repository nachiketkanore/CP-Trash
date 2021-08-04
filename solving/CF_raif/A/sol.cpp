/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 06:33:33 PM IST
(ツ) Ignorant men don't know what good they hold in their hands until they've flung it away.
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
	
	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bool turn = !(x1 == x2 || y1 == y2);
		int ans = abs(x2 - x1) + abs(y2 - y1);
		if (turn) ans += 2;
		cout << ans << '\n';
	}
}
