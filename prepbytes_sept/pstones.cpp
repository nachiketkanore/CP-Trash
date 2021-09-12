/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 02:46:27 PM IST
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
		int N, ans = 0;
		cin >> N;
		vector<int> A(N);
		F0R (i,N) cin >> A[i];
		F0R (i,N) {
			int Bi;
			cin >> Bi;
			if (A[i] - Bi > 0)
				ans += A[i] - Bi;
		}
		cout << ans << '\n';
	}
}
