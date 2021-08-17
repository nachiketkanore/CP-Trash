/**
 *    Author: Nachiket Kanore
 *    Created: Friday 06 August 2021 04:41:31 PM IST
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
		int A[4]; F0R (i,4) cin >> A[i];
		sort(A, A + 4);
		bool all_same = true;
		bool all_diff = true;
		for (int i = 1; i < 4; i++) {
			all_same &= A[i] == A[0];
			all_diff &= A[i] != A[i-1];
		}
		if (all_same) cout << "0\n";
		else if (all_diff) cout << "2\n";
		else {
			bool three_same = (A[0] == A[1] && A[1] == A[2]) || (A[1] == A[2] && A[2] == A[3]);
			if (three_same) cout << "1\n";
			else cout << "2\n";
		}
	}
}
