/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 July 2021 10:24:32 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int ans = 0, pairs = 0;
	for (int i = n-1; i >= 0; i--) {
		pairs += a[i] / 2;
		if (a[i] % 2 == 1 && pairs > 0) {
			ans += 1;
			pairs--;
		}
	}
	ans += (2 * pairs) / 3;
	cout << ans;
}
