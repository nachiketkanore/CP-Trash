/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 04 September 2021 03:29:37 PM IST
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
	for (int N: {1233242}) {
		cout << N << '\n';
		FOR (base,2,100) {
			cout << "base = " << base << " : ";
			int val = N, f = 0;
			while (val) {
				f += val % base;
				cout << val % base << ' ';
				val /= base;
			}
			cout << " sod = ";
			cout << f << '\n';
		}
	}
}
