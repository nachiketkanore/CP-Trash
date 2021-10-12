/**
 *    Author: Nachiket Kanore
 *    Created: Friday 30 July 2021 12:51:25 PM IST
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

struct Hello {
	array<int,3> f;
	int N;
	Hello(int N): N(N) {
		f.at(N);
	}
};

void hello_world() {
	Hello nachiket(21);
	nachiket.f.begin();
}

void test() {
	static const int MOD = 1e9 + 7;
	int N;
	cin >> N;
	int A[N]; F0R (i,N) cin >> A[i];
	for (int i = 0; i < N; i++) {
		if (i > 0)
			A[i] += A[i-1];
		if (A[i] >= MOD) 
			A[i] -= MOD;
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(ALL(A));
		for (int i = 1; i < N; i++) {
			A[i] += A[i-1];
		}
	}
}
