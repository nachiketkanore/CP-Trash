/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 12 August 2021 09:46:03 PM IST
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

int brute(vector<int> A) {
	const int N = A.size();
	int ans = 1e9;
	F0R (i,N) {
		int val = A[i];
		int req = 0;
		for (int j = i; j >= 0; j--) {
			req += abs(A[j] - val);
			val--;
		}
		val = A[i] + 1;
		for (int j = i + 1; j < N; j++) {
			req += abs(A[j] - val);
			val++;
		}
		cmin(ans, req);
	}
	assert(ans != 1e9);
	return ans;
}

int32_t main() {
	int N;
	cin >> N;
	vector<int> A(N);
	F0R (i,N) cin >> A[i];
	cout << brute(A);
}
