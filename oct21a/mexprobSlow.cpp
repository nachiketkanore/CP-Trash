/**
 *    Author: Nachiket Kanore
 *    Created: Monday 04 October 2021 04:13:10 PM IST
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

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

bool have[1000000];

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N), B; 
	F0R (i,N) { cin >> A[i]; }
	F0R (i,N) {
		F0R (i,N+1) have[i] = false;
		int mex = 0;
		for (int j = i; j < N; j++) {
			have[A[j]] = true;
			while (mex <= N && have[mex]) ++mex;
			B.push_back(mex);
		}
	}
	sort(ALL(B));
	cout << B[--K] << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
