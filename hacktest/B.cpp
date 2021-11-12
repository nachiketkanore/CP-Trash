/**
 *    Author: Nachiket Kanore
 *    Created: Friday 12 November 2021 11:54:07 AM IST
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
	int N; cin >> N;
	int A[N];
	int sum = 0;
	F0R (i,N) {
		cin >> A[i];
		sum += A[i];
	}
	FOR (make, 1, 1e5) {
		if (make * N > sum) {
			cout << make << '\n';
			return 0;
		}
	}
	assert(false);
}
