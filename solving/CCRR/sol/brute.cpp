/*
Author: Nachiket Kanore
Created: Thursday 25 February 2021 01:01:46 PM IST
(ツ) In times of change learners inherit the earth, while the learned find themselves beautifully equipped to deal with a world that no longer exists.
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
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 5e5 + 5;
int n, q, a[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	FOR (i,1,n) {
		cin >> a[i];
	}
	while (q--) {
		int typ, L, R;	cin >> typ >> L >> R;
		if (typ == 1) a[L] = R;
		else {
			int ans = 0, mx = 0;
			FOR (i,L,R) cmax(mx, a[i]);
			FOR (i,L,R) ans += (mx - a[i] + 1) / 2;
			cout << ans << '\n';
		}
	}
}
