/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 July 2021 12:26:15 AM IST
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

const int N = 2e7;
int a[N+1];

int32_t main() {
	FOR (i,1,N) {
		a[i] = 1;
		for (int j = 1; j < i; j++) {
			if (i % j) {
				a[i] += a[j];
				break;
			}
		}
		// cerr << i << " : " << a[i] << '\n';
		// cerr << a[i] << ' ';
	}
	FOR (i,1,N) {
		a[i] += a[i-1];
		if (i < 20) {
			cerr << a[i] << ' ';
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int L, R;
		cin >> L >> R;
		cout << a[R]-a[L-1] << '\n';
	}
}
20
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
