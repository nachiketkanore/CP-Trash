/*
Author: Nachiket Kanore
Created: Wednesday 02 December 2020 04:10:52 PM IST
(ツ) While we try to teach our children all about life, our children teach us what life is all about.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <math.h>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

bool canForm(vector<int> vals) {
	sort(vals.begin(), vals.end());
	return vals[0]+vals[1] > vals[2];
}

using ld = long double;
ld getArea(vector<int> a) {
	ld s = (ld)(a[0]+a[1]+a[2])/2;
	s = (ld)s*(s-a[0])*(s-a[1])*(s-a[2]);
	s = (ld)sqrt(s);
	return s;
}

void solve() {
	vector<int> a(3);	for(int& x : a) cin >> x;
	int k;	cin >> k;
	ld ans = 0;
	for (int i = 0; i < 3; i++) {
		for (int inc = 0; inc <= k; inc++) {
			a[i] += inc;
			if (canForm(a)) {
				ans = max(ans, getArea(a));
			}
			a[i] -= inc;
		}
	}

	printf("%0.6Lf\n", ans);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--)	solve();
}
