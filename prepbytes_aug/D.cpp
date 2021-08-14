/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 14 August 2021 01:11:51 AM IST
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

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int A, B, X, Y;
		cin >> A >> B >> X >> Y;
		int x = X / __gcd(X, Y);
		int y = Y / __gcd(X, Y);

		int k1 = A / x, k2 = B / y;
		int km = min(k1, k2);
		k1 = k2 = km;

		if (km == 0) {
			cout << "0 0\n";
		} else {
			cout << k1 * x << ' ' << k2 * y << '\n';
		}
	}
}
